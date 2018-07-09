from time import process_time, sleep
from random import uniform
from statistics import median

import Log


class UltrasonicSensor:
    trigger_time = 0.00001
    sonic_speed_mm_per_second = 343000

    def __init__(self, pin_trigger, pin_echo, gpio):
        self.gpio = gpio
        self.pin_trigger = pin_trigger
        self.pin_echo = pin_echo

        self.gpio.setup(self.pin_trigger, self.gpio.OUT)
        self.gpio.setup(self.pin_echo, self.gpio.IN)

        self.logger = Log.instance(
            'UltrasonicSensor[{}/{}]'.format(pin_trigger, pin_echo))

    @staticmethod
    def fake_distance(min, max):
        return uniform(min, max)

    def median_distance(self, measure_millis):
        if measure_millis < 0:
            raise ValueError("millis negative: {}".format(measure_millis))
        distances = []
        start = process_time()
        stop = start + measure_millis / 1000  # time is in seconds
        while process_time() <= stop:
            distances.append(self.distance())
        n = len(distances)
        self.logger.debug('{} distances in {} ms'.format(n, measure_millis))
        distance_mm = median(distances)
        return int(distance_mm)

    def n_median_distance(self, n):
        distances = []
        for i in range(0, n):
            distances.append(self.distance())
        self.logger.debug('{} distances'.format(n))
        distance_mm = median(distances)
        return int(distance_mm)

    def distance(self):
        self.gpio.output(self.pin_trigger, True)
        sleep(self.trigger_time)
        self.gpio.output(self.pin_trigger, False)
        start, stop = None, None
        while self.gpio.input(self.pin_echo) == 0:
            start = process_time()
        while self.gpio.input(self.pin_echo) == 1:
            stop = process_time()
        if start is None:
            self.logger.info('echo was not 0 (start is None)')
        if stop is None:
            self.logger.info('echo was not 1 (stop is None)')
        if stop is None or start is None:
            raise ValueError(
                "{} didn't switch from HIGH to LOW".format(self.pin_echo))
        diff = stop - start
        dist = (diff * self.sonic_speed_mm_per_second) / 2  # back and forth
        return int(dist)
