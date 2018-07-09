#!/usr/bin/env python3


import cv2
import os

from ImageAnalyzer import ImageAnalyzer
import Log

logger = Log.instance('ImageAnalyzerDemo')


def estimate_distances(pics_dir):
    analyzer = ImageAnalyzer()
    for (path, _, files) in os.walk(pics_dir):
        for f in sorted(files):
            pic = os.path.join(path, f)
            img = cv2.imread(pic)
            try:
                px, mm = analyzer.calculate_distance(img)
                logger.debug('distance: {:4d}px\t{:3.0f}mm'.format(px, mm))
            except Exception as e:
                logger.error(e)


if __name__ == '__main__':
    estimate_distances('pics')
