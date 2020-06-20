#!/usr/bin/env python3

import os

import zmq

context = zmq.Context()
sock_address = os.environ.get('SOCK_ADDRESS', 'localhost:5555')
socket = context.socket(zmq.SUB)
socket.connect(f'tcp://{sock_address}')
socket.setsockopt(zmq.SUBSCRIBE, b'timecube')

while True:
    payload = socket.recv_string()
    topic, identifier, side = payload.split()
    print(f'topic={topic}, identifier={identifier}, side={side}')
