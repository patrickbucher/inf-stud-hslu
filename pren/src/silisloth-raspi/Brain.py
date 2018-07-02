#!/usr/bin/env python3

import RPi.GPIO as GPIO
import time

from Arduino import Arduino
from EndSwitch import EndSwitch
import Log
from TargetDetection import TargetDetection
from TcpServer import TcpServer
from UltrasonicSensor import UltrasonicSensor

"""drive for fixed time_to_freight (True) or by ultrasonic sensor (False)"""
drive_by_time = True

"""fixed time to drive to reach the freight"""
time_to_freight = 3.10

"""number of measurements a ultrasonic sensor does to take the median"""
measure_n_distances = 15

"""vertical distance between z ultrasonic sensor and the freight"""
z_ultrasonic_freight_mm = 140

"""horizontal distance between x ultrasonic sensor and the freight"""
ultrasonic_freight_mm = 70

"""required distance for x ultrasonic sensor to pick up distance"""
pickup_x_dist_mm = 2690 - ultrasonic_freight_mm + 115

"""horizontal distance between start pole and freight"""
freight_distance_mm = 250

"""horizontal distance between camera and x ultrasonic sensor"""
cam_ultrasonic_mm = 50

"""vertical distance the freight is raised/lowered per second"""
z_delta_per_second_mm = 66

"""serial port to Arduino"""
arduino_device = '/dev/ttyACM0'

"""optical distance to target field to reach before decelerating"""
critical_mm = 150

"""final distance to decelerate before pole"""
final_distance_mm = 250

"""distance between x-ultrasonic sensor and start pole"""
x_ultrasonic_start_pole_mm = 300


class Brain():
    def __init__(self):
        GPIO.setmode(GPIO.BCM)
        self.sensor_x = UltrasonicSensor(18, 24, GPIO)
        self.sensor_z = UltrasonicSensor(17, 23, GPIO)
        self.arduino = Arduino(arduino_device)
        self.server = TcpServer()
        self.eye = TargetDetection(True)
        self.end_switch = EndSwitch(GPIO)
        self.logger = Log.instance('Brain')
        self.initial_distance_mm, _ = self.distances(z=False)

    def start(self):
        try:
            self.logger.info('Silisloth has started its work')
            self.drive_to_freight(drive_by_time)
            self.pick_up_freight()
            self.spot_target_field()
            cam_to_target, us_to_pole = self.approach_target_field(critical_mm)
            end_us_to_pole = self.calc_end_distance(cam_to_target, us_to_pole)
            self.move_freight_over_target(end_us_to_pole)
            self.drop_freight()
            self.drive_to_pole()
            self.arduino.halt()
            self.logger.info('Silisloth has finished its work')

        except KeyboardInterrupt:
            self.logger.info('interrupted by user')

        finally:
            GPIO.cleanup()
            self.logger.info('cleaned up GPIO')
            self.server.close()
            self.logger.info('closed TCP server')

    def drive_to_freight(self, drive_by_time=False):
        self.arduino.move_off()
        if drive_by_time:
            time.sleep(time_to_freight)
        else:
            self.logger.info('pickup distance: {}'.format(pickup_x_dist_mm))
            x = None
            while x is None or x > pickup_x_dist_mm:
                try:
                    try_x, _ = self.distances(z=False)
                    if try_x < 2000:  # plausibility check
                        continue
                    else:
                        x = try_x
                    self.logger.debug('x distance: {}mm'.format(x))
                    self.logger.debug('to freight: {}mm'.format(
                        self.initial_distance_mm - freight_distance_mm))
                except ValueError as e:
                    self.logger.fatal(e)

    def pick_up_freight(self):
        try:
            x, z = self.distances()
            self.logger.info('distance to freight {}mm'.format(z))
            self.arduino.pick_up(z)
            self.send_coordinates(self.x0ref(x), -1)
            self.logger.info('started picking up freight')
        except ValueError as e:
            self.logger.fatal(e)

        self.logger.debug('wait until freight is picked')
        x, _ = self.distances(z=False)
        while not self.arduino.freight_ready():
            self.send_coordinates(self.x0ref(x), -1)
            time.sleep(0.5)
        self.logger.info('freight was picked, pulling it up')

    def spot_target_field(self):
        dist_mm = None
        while dist_mm is None:
            try:
                dist_mm = self.eye.distance_to_target()
                x, z = self.distances()
                z += z_ultrasonic_freight_mm
                self.send_coordinates(self.x0ref(x), z)
            except Exception as e:
                self.logger.debug(e)

        msg = 'camera detected target: {}mm away'.format(dist_mm)
        self.logger.info(msg)
        self.arduino.decelerate()
        self.logger.info('decelerate')

    def approach_target_field(self, critical_distance):
        dist_mm = None
        while dist_mm is None or dist_mm >= critical_distance:
            try:
                dist_mm = self.eye.distance_to_target()
                x, z = self.distances(z=False)
                self.send_coordinates(self.x0ref(x), -1)
            except Exception as e:
                self.logger.debug(e)

        x_dist_end_mm = None
        while x_dist_end_mm is None:
            try:
                x_dist_end_mm = self.sensor_x.n_median_distance(
                    measure_n_distances)
            except ValueError as e:
                self.logger.fatal(e)

        return int(dist_mm), int(x_dist_end_mm)

    def calc_end_distance(self, cam_to_target, us_to_pole):
        end_us_pole_dist_mm = us_to_pole
        end_us_pole_dist_mm -= cam_to_target
        end_us_pole_dist_mm -= cam_ultrasonic_mm
        end_us_pole_dist_mm -= ultrasonic_freight_mm

        self.logger.info('cam/target:  {}mm'.format(cam_to_target))
        self.logger.info('us/pole:     {}mm'.format(us_to_pole))
        self.logger.info('end us/pole: {}mm'.format(end_us_pole_dist_mm))

        return end_us_pole_dist_mm

    def move_freight_over_target(self, end):
        x = None
        while x is None or x > end:
            try:
                x, z = self.distances(z=False)
                self.send_coordinates(self.x0ref(x), -1)
                self.logger.info('to pole: {}mm, wanted: {}mm'.format(x, end))
            except ValueError as e:
                self.logger.fatal(e)
        self.logger.info('position over target reached')

    def drop_freight(self):
        z = None
        while z is None:
            try:
                x, z = self.distances()
            except ValueError as e:
                self.logger.fata(e)
        self.logger.info('drop freight by {}mm'.format(z))
        self.arduino.drop_freight(z)

        self.logger.debug('wait until freight is released')
        _, z = self.distances(x=False)
        while not self.arduino.freight_ready():
            self.send_coordinates(self.x0ref(x), z)
            z -= z_delta_per_second_mm / 2
            time.sleep(0.5)
        self.logger.info('freight was released, continue')

    def drive_to_pole(self):
        self.logger.info('approach pole')
        x = None
        while x is None or x > final_distance_mm:
            x, _ = self.distances(z=False)
            self.logger.info('distance to pole: {}mm'.format(x))
        self.arduino.decelerate()
        self.logger.info('wait until end switch is pressed')
        while not self.end_switch.is_pressed():
            self.send_coordinates(-1, -1)
        self.logger.info('end switch was pressed')

    def send_coordinates(self, x, z):
        self.server.send('x={};z={}\r\n'.format(x, z).encode())

    def distances(self, x=True, z=True):
        x_dist, z_dist = -1, -1
        try:
            if x:
                x_dist = self.sensor_x.n_median_distance(measure_n_distances)
            if z:
                z_dist = self.sensor_z.n_median_distance(measure_n_distances)
        except ValueError as e:
            self.logger.info(e)
        return x_dist, z_dist

    def x0ref(self, x):
        return self.initial_distance_mm - x + x_ultrasonic_start_pole_mm


if __name__ == '__main__':
    brain = Brain()
    brain.start()
