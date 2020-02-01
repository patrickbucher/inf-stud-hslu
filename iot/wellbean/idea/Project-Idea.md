---
title: Workplace Quality
subtitle: Internet of Things
author: Group 2
---

# Project Idea

The goal of the project is to monitor and assess the quality of a workplace.
Multiple parameters should be measured automatically, like temperature,
brightness, air pressure, humidity, noise level, and air quality (air
composition of different gases). Additionaly, the person sitting at the working
place should be able to track interruptions (from co-workers or other sources)
and his well-being manually, for which the parameters and exact mechanisms are
still to be defined.

The data is gathered on the Raspberry Pi Zero W and forwarded to an InfluxDB
instance running in the Cloud. A dashboard will be created to keep track of the
parameters mentioned above, so that the user can assess the changing workplace
conditions, and can figure out which parameters correlate with his subjective
measurements of well-being.

## Hardware

- [Raspberry Pi Zero W](https://www.raspberrypi.org/products/raspberry-pi-zero-w/)
- [Enviro+ Hat](https://shop.pimoroni.com/products/enviro-plus)
- [Arduino](https://store.arduino.cc/arduino-uno-rev3)

## Software Components

- [D3.js](https://d3js.org/) for the Dashboard (Visualization)
- [InfluxDB](https://www.influxdata.com/) on a Cloud Server (Data Store)
- Python program on the Raspberry Pi Zero W (gathering and forwarding sensor data)
- C program on the Arduino (gathering additional inputs and sensor data)
