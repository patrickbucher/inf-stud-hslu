#!/usr/bin/env python3

from Arduino import Arduino
import Log

arduino = Arduino('/dev/ttyACM0')
try:
    while True:
        cmd = input()
        arduino.write(cmd)
except KeyboardInterrupt:
    Log.instance('ArduinoMock').info('stopped by the user')
