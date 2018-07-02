from serial import Serial

import Log


class Arduino:

    def __init__(self, device):
        super().__init__()
        self.logger = Log.instance('Arduino')
        try:
            self.port = Serial(device, baudrate=9600, timeout=1.0)
        except Exception as e:
            self.logger.error(e)

    def freight_ready(self):
        if self.port.in_waiting > 0:
            c = self.port.read()
            self.logger.info('read "{}"'.format(c))
            return c.decode() == 'L'
        else:
            return False

    def write(self, cmd):
        self.port.write(cmd.encode())
        self.port.flush()
        self.logger.info('sent command: "{}"'.format(cmd))

    def move_off(self):
        self.write('G')

    def pick_up(self, height):
        cmd = 'S{};'.format(height)
        self.write(cmd)

    def decelerate(self):
        self.write('D')

    def drop_freight(self, height):
        cmd = 'S{};'.format(height)
        self.write(cmd)

    def halt(self):
        self.write('H')
