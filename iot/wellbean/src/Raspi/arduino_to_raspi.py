#!/usr/bin/env python3

from common import sock, reply_ack

import pickle
import serial
import time
import zmq

arduino = '/dev/ttyACM0'
baudrate = 9600

port = serial.Serial(arduino, baudrate=baudrate)
time.sleep(1)

context = zmq.Context()
socket = context.socket(zmq.REQ)
socket.connect(sock)

while port.read() != b'\n':
    # discard first line, probably incomplete
    pass

while True:
    buf = []
    eol = False
    while not eol:
        byte = port.read()
        if byte == b'\n':
            eol = True
        else:
            buf.append(byte.decode())
    message = ''.join(buf)
    items = message.split(',')
    measurements = {}
    for item in items:
        pair = item.split('=')
        if len(pair) != 2:
            continue
        key, value = pair[0], pair[1]
        measurements[key] = value
    payload = pickle.dumps(measurements)
    socket.send(payload)
    reply = socket.recv()
    if reply == reply_ack:
        print('ok')
    else:
        print('error')
