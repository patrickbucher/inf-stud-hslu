import cv2
import picamera
import numpy as np
import os
import shutil
import time

from ImageAnalyzer import ImageAnalyzer
import Log

res_ultra = dict(x=2400, y=2400)
res_high = dict(x=1088, y=1920)
res_medium = dict(x=736, y=1280)
res_low = dict(x=480, y=640)

resolution = res_low

dir_name = './piclog'


class TargetDetection:

    def __init__(self, store_pics=False):
        self.cam = picamera.PiCamera()
        self.cam.resolution = (resolution['x'], resolution['y'])
        self.analyzer = ImageAnalyzer(adaptive_threshold=True)
        self.logger = Log.instance('TargetDetection')
        self.store_pics = store_pics

        if os.path.exists(dir_name):
            shutil.rmtree(dir_name)
        os.makedirs(dir_name)

    def distance_to_target(self):
        start = time.process_time()
        pic = np.empty((resolution['y'], resolution['x'], 3), dtype=np.uint8)
        self.cam.capture(pic, 'bgr')
        if self.store_pics:
            save_start = time.process_time()
            save_to = os.path.join(dir_name, str(int(time.time())) + '.jpg')
            self.logger.debug('save to: {}'.format(save_to))
            cv2.imwrite(save_to, pic)
            self.logger.debug('stored picture at "{}"'.format(save_to))
            save_end = time.process_time()
            self.logger.info('{:4d}ms to save image'.format(int((save_end - save_start) * 1000)))
        try:
            px, mm = self.analyzer.calculate_distance(pic)
            end = time.process_time()
            diff = int((end - start) * 1000)
            msg = 'distance: {:4d}px\t{:3.0f}mm\t{:4d}ms'.format(px, mm, diff)
            self.logger.info(msg)
            return mm
        except Exception as e:
            end = time.process_time()
            self.logger.info(
                '{:4d}ms, no distance detected'.format(int((end - start) * 1000)))
            self.logger.error(e)
