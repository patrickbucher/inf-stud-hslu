#!/usr/bin/env python3

import json
import os
import time

import zmq

from cube import Cube
import identity


def main():
    cube = Cube()

    context = zmq.Context()
    bind_address = os.environ.get('BIND_ADDRESS', '0.0.0.0:5555')
    socket = context.socket(zmq.PUB)
    socket.bind(f'tcp://{bind_address}')

    identifier = identity.acquire_identity()

    while True:
        position = cube.get_position()
        print(f'current position: {position}')
        if position != -1:
            socket.send_string(f'timecube {identifier} {position}')
        time.sleep(1.0)


if __name__ == '__main__':
    main()
