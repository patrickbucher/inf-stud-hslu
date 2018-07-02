import cv2
import math

import Log


class ImageAnalyzer:
    """
    This class processes pictures of a target field consisting of concentric
    black and white squares. The distance to the innermost detected square
    is calculated and returned both in pixels and millimeters.

    The target field is considered to enter the image from the top, thus a
    positive distance means the center is over the middle line,
    and a negative distance means the center is under the
    middle line.
    """

    STATIC_THRESHOLD = 120

    MIN_SQUARE_AREA_RATIO = 0.005  # 0.5% of the image
    MAX_SQUARE_AREA_RATIO = 0.950  # 95% of the image

    MIN_SQUARE_XY_RATIO = 0.75
    MAX_SQUARE_XY_RATIO = 1.25

    MAX_PERIMETER_DELTA_RATIO = 0.1

    innermost_square_height_mm = 60

    def __init__(self, innermost_square_height_mm=60,
                 adaptive_threshold=False):
        self.innermost_square_height = innermost_square_height_mm
        self.logger = Log.instance('ImageAnalyzer')
        self.adaptive_threshold = adaptive_threshold

    def calculate_distance(self, image_bgr):
        """Calculates the distance from the middle line of the image to the
        center of the innermost (smallest) square shaped field on the
        picture. The distance is returned both in pixels and centimeters.
        Positive values denote a detected center above the middle line,
        negative values a detected center below the middle line."""
        image_rgb = cv2.cvtColor(image_bgr, cv2.COLOR_BGR2RGB)
        threshold = self.to_grayscale(image_rgb)

        _, contours, hierarchy = cv2.findContours(threshold.copy(),
                                                  cv2.RETR_TREE,
                                                  cv2.CHAIN_APPROX_SIMPLE)

        candidates = []
        for item in zip(contours, hierarchy[0]):
            cont = item[0]
            hier = item[1]
            if self.has_neighbours(hier):
                continue
            if not self.has_square_area(image_rgb, cont):
                continue
            if not self.is_square_shaped(cont):
                continue
            candidates.append((cont, hier))

        self.logger.debug('found {} candidates'.format(len(candidates)))
        smallest = self.find_smallest(candidates)
        if smallest is None:
            raise Exception('No square detected on given image')
        dist_px, dist_mm = self.estimate_distance_to_center(image_rgb,
                                                            smallest)

        self.logger.info(
            "calculated distance: px={:d}, mm={:d}".format(dist_px, dist_mm))
        return dist_px, dist_mm

    @staticmethod
    def determine_center(contours):
        """determines the center of a contour, returns a tuple of x/x
        coordinates"""
        cx, cy = -1, -1
        m = cv2.moments(contours)
        m00 = m['m00']
        if m00 > 0:
            cx = int(m['m10'] / m00)
            cy = int(m['m01'] / m00)
        return cx, cy

    def to_grayscale(self, image):
        """creates a grayscale image determined by a static threshold
        or using adaptive thresholding"""
        image_gray = cv2.cvtColor(image, cv2.COLOR_RGB2GRAY)
        blurred = cv2.blur(image_gray, (5, 5))
        if self.adaptive_threshold:
            neighbourhood = int(image.shape[0] / 4.0)
            if neighbourhood % 2 == 0:
                neighbourhood += 1  # must be a odd number
            grayscale = cv2.adaptiveThreshold(blurred, 255,
                                              cv2.ADAPTIVE_THRESH_MEAN_C,
                                              cv2.THRESH_BINARY, neighbourhood,
                                              10)
        else:
            _, grayscale = cv2.threshold(blurred, self.STATIC_THRESHOLD, 255,
                                         cv2.THRESH_BINARY)
        return grayscale

    def is_square_shaped(self, contours):
        """checks whether or not the given contours are square shaped"""
        peri = cv2.arcLength(contours, True)
        corners = cv2.approxPolyDP(contours,
                                   self.MAX_PERIMETER_DELTA_RATIO * peri, True)
        if len(corners) != 4:
            return False
        (x, y, w, h) = cv2.boundingRect(corners)
        (cx, cy) = self.determine_center(contours)
        width_height_ratio = w / float(h)
        sensible_width_height_ratio = (
                self.MAX_SQUARE_XY_RATIO > width_height_ratio >
                self.MIN_SQUARE_XY_RATIO)

        return sensible_width_height_ratio

    def estimate_distance_to_center(self, image, contours):
        """calculates y distance from the image middle line to the contour's
        center"""
        h, _, _ = image.shape
        perimeter = cv2.arcLength(contours, False)
        innermost_square_height_px = perimeter / 4.0
        mm_in_pixels = innermost_square_height_px / float(
            self.innermost_square_height_mm)
        _, cy = self.determine_center(contours)
        dist_px = h / 2 - cy
        dist_mm = dist_px / mm_in_pixels
        return int(dist_px), int(dist_mm)

    @staticmethod
    def has_neighbours(hierarchy):
        """checks wheter or not the given hierarchy has any neighbours"""
        return hierarchy[0] != -1 or hierarchy[1] != -1

    def has_square_area(self, image, contours):
        """checks whether or not the given contours have a reasonable area"""
        h, w, _ = image.shape
        square_area_px = cv2.contourArea(contours)
        image_area_px = w * h
        min = self.MIN_SQUARE_AREA_RATIO * image_area_px
        max = self.MAX_SQUARE_AREA_RATIO * image_area_px
        return max > square_area_px > min

    @staticmethod
    def find_smallest(cont_hier_list):
        """finds the contours with smallest area in the cont_hier_list that
        has a parent but no childs"""
        min_area = math.inf
        min_contours = None
        for item in cont_hier_list:
            cont = item[0]
            hier = item[1]
            area = cv2.contourArea(cont)
            if area < min_area and hier[2] == -1 and hier[3] != -1:
                min_area = area
                min_contours = cont
        return min_contours

    @staticmethod
    def calc_middle(image):
        """calculates the middle (y axis) of the given image"""
        h, _, _ = image.shape
        middle = int(h / 2)
        return middle
