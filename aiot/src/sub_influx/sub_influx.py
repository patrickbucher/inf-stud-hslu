#!/usr/bin/env python3

import os

import zmq
from influxdb_client import InfluxDBClient, Point
from influxdb_client.client.write_api import SYNCHRONOUS


context = zmq.Context()
sock_address = os.environ.get('SOCK_ADDRESS', 'localhost:5555')
socket = context.socket(zmq.SUB)
socket.connect(f'tcp://{sock_address}')
socket.setsockopt(zmq.SUBSCRIBE, b'timecube')

bucket = 'timecube'
client = InfluxDBClient.from_config_file('config.ini')

write_api = client.write_api(write_options=SYNCHRONOUS)
query_api = client.query_api()

while True:
    payload = socket.recv_string()
    topic, identifier, side = payload.split()
    print(f'topic={topic}, identifier={identifier}, side={side}')

    p = Point('measurement').tag('identifier', identifier).field('side', side)

    try:
        write_api.write(bucket=bucket, record=p)
    except ConnectionError as e:
        print(e)
