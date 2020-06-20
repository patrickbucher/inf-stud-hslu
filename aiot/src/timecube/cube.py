import logging

from Adafruit_ADS1x15 import ADS1115


class Cube:
    """The Cube class allows for position detection using an accelerometer."""

    GAIN = 1
    DATA_RATE = 128
    RESOLUTION = float(32768)

    POSITION_VALUES = {
        '112': 1,
        '101': 2,
        '211': 3,
        '011': 4,
        '121': 5,
        '110': 6,
    }

    def __init__(self):
        self.adc = ADS1115()
        self.logger = logging.getLogger(__name__)

    def get_position(self):
        """
        get_position returns the cube's current position.

        If the position was detected, a value (range 1..6) is returned.
        If the position could not be detected, -1 is returned.
        """
        values = [0, 0, 0]
        for axis in range(3):
            try:
                measurement = self.adc.read_adc(axis,
                                                gain=Cube.GAIN,
                                                data_rate=Cube.DATA_RATE)
                values[axis] = Cube.normalize(measurement)
            except OSError as err:
                logger.error(err)
                continue
        return Cube.upper_side(values)

    @staticmethod
    def upper_side(values):
        key = '{:d}{:d}{:d}'.format(values[0], values[1], values[2])
        if key in Cube.POSITION_VALUES:
            return Cube.POSITION_VALUES[key]
        return -1

    @staticmethod
    def round_to(value, granularity):
        return round(value * 1/granularity) * granularity

    @staticmethod
    def normalize(measurement):
        return int(Cube.round_to(
            float(measurement) / Cube.RESOLUTION - 0.3, 0.1) * 10)
