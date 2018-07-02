#!/usr/bin/env python3


import cv2
import os
from statistics import mean, median
import time

from ImageAnalyzer import ImageAnalyzer
import Log

logger = Log.instance('ImageAnalyzerBenchmark')


def process(pics_dir, adaptive_threshold):
    analyzer = ImageAnalyzer(adaptive_threshold=adaptive_threshold)
    timings = []
    for (path, _, files) in os.walk(pics_dir):
        for f in sorted(files):
            pic = os.path.join(path, f)
            img = cv2.imread(pic)
            try:
                start = time.process_time()
                px, mm = analyzer.calculate_distance(img)
                end = time.process_time()
                timings.append(int((end - start) * 1000))
                logger.debug('distance: {:4d}px\t{:3.0f}mm'.format(px, mm))
            except Exception as e:
                logger.error(e)
    return timings


if __name__ == '__main__':
    static_timings = process('pics', False)
    adaptive_timings = process('pics', True)
    logger.info('results: static={}, adaptive={}'.format(len(static_timings),
        len(adaptive_timings)))
    logger.info('mean: static={}, adaptive={}'.format(mean(static_timings),
        mean(adaptive_timings)))
    logger.info('median: static={}, adaptive={}'.format(median(static_timings),
        median(adaptive_timings)))
