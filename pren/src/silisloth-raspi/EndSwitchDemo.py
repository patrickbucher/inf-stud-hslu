#!/usr/bin/env python3

import RPi.GPIO as GPIO

from EndSwitch import EndSwitch

try:
    GPIO.setmode(GPIO.BCM)
    switch = EndSwitch(GPIO)
    while not switch.is_pressed():
        pass
    print('pressesd')
except KeyboardInterrupt:
    print('interrupted by the user')
finally:
    GPIO.cleanup()
