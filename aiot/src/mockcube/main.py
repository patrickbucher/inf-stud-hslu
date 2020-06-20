#!/usr/bin/env python3

import os
import random
import time
import uuid

import zmq


def main():
    context = zmq.Context()
    bind_address = os.environ.get('BIND_ADDRESS', '0.0.0.0:5555')
    socket = context.socket(zmq.PUB)
    socket.bind(f'tcp://{bind_address}')

    identifier = uuid.uuid4()

    while True:
        position = random.randint(0, 5) + 1
        # report the same side for a duration between ten seconds to one hour
        seconds = random.randint(10, 3600)
        for i in range(0, seconds + 1):
            print(f'current position: {position}')
            socket.send_string(f'timecube {identifier} {position}')
            time.sleep(1.0)


if __name__ == '__main__':
    main()
