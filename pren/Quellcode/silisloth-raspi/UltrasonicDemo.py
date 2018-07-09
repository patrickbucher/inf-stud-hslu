#!/usr/bin/env python3

import RPi.GPIO as GPIO
import time
from UltrasonicSensor import UltrasonicSensor

GPIO.setmode(GPIO.BCM)

sensor_x = UltrasonicSensor(18, 24, GPIO)
sensor_z = UltrasonicSensor(17, 23, GPIO)

n = 15

try:
    while True:
        start = time.time()
        x = sensor_x.n_median_distance(n)
        x_end = time.time()
        z = sensor_z.n_median_distance(n)
        z_end = time.time()
        print('x:{:3.0f}mm, {} times in {:3.1f}s'.format(x, n, x_end - start))
        print('z:{:3.0f}mm, {} times in {:3.1f}s'.format(z, n, z_end - start))
except KeyboardInterrupt:
    print('stopped by the user')
finally:
    GPIO.cleanup()
