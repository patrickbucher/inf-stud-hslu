#!/usr/bin/env python3

import Log
from TargetDetection import TargetDetection


def main():
    logger = Log.instance('TargetDetectionDemo')
    detection = TargetDetection(True)
    try:
        while True:
            try:
                dist_mm = detection.distance_to_target()
                if dist_mm is not None:
                    msg = 'distance to target: {:4.0f}mm'.format(dist_mm)
                    logger.info(msg)
            except Exception as e:
                logger.error(e)
    except KeyboardInterrupt:
        logger.info('interrupted by the user')
    except Exception as e:
        logger.error(e)


if __name__ == '__main__':
    main()
