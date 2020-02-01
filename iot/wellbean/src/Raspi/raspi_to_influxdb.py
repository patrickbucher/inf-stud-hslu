#!/usr/bin/env python3

import pickle
import zmq

from influxdb import InfluxDBClient

from common import bind, reply_ack, influx_host, influx_port, influx_db

context = zmq.Context()
socket = context.socket(zmq.REP)
socket.bind(bind)

influx = InfluxDBClient(host=influx_host, port=influx_port)
influx.switch_database(influx_db)

while True:
    message = socket.recv()
    measurements = pickle.loads(message)
    json_body = []
    for key, value in measurements.items():
        item = {'measurement': key, 'fields': {'value': value}}
        json_body.append(item)
    influx.write_points(json_body)
    socket.send(reply_ack)
