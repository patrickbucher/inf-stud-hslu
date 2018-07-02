import time

import Log

pin = 21


class EndSwitch:
    def __init__(self, gpio):
        self.gpio = gpio
        self.gpio.setup(pin, gpio.IN, pull_up_down=gpio.PUD_DOWN)
        self.gpio.add_event_detect(pin, self.gpio.RISING,
                                   callback=self.pushed_button)
        self.pressed = False
        self.logger = Log.instance('EndSwitch')

    def is_pressed(self):
        return self.pressed

    def pushed_button(self, channel):
        if self.gpio.input(pin) == 1:
            time.sleep(0.1)
            if self.gpio.input(pin) == 1:
                self.pressed = True
