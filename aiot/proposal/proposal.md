---
title: 'Project Proposal «TimeCube»'
subtitle: 'Advanced Internet of Things'
author: 'Group 4 (Patrick Bucher, Pascal Kiser, Benno Kuhn, André Ruckstuhl)'
---

_TimeCube_ is a smart IoT device that allows for easy time tracking.

# Motivation

It is often necessary to track the time that is spent for different projects. For this purpose, various programs, mobile apps, and web services do exist.

However, the context switch from one project to another (say, being interrupted by a support telephone call while programming), happens often immediately, and doesn't allow updating the time tracking tool.

After the interruption (support call, talk with the boss about another project) is over, one probably has already forgotten at what time the interruption happened, and, in the evening, how much time the interruption did cost.

The tab with the time tracking web service, or the time tracking program on the desktop, respectively, is probably hidden by other tabs and windows througout the day. Time tracking is invisible most of the day, so one forgets to do this task.

There must be a better way to track the way somebody is spending his or her time, especially in respect to quick context switches.

# Approach

The idea is to allow time tracking with a simple hardware device that is always in one's sight: a cube, henceforth being called _TimeCube_.

_TimeCube_ has six sides. Every side denotes a different project one is working on, for example:

1. Programming
2. Maintenance
3. Administrative Tasks
4. Customer Support
5. Learning new Things
6. Taking a Break/Work Day Finished

The side on top denotes the currently active project. While side one (_Programming_) is on the top, the time is booked on that project. When a customer calls, the cube is moved over, so that side four (_Customer Support_) is on top, thus reporting the time spent on that project. When one is leaving the office for lunch, or leaving for the evening, side six is moved to the top, so that the time is reported as being off-duty.

# Techniques

The approach described requires for various techniques being implemented, which require different equipment, appliances, facilities:

1. Shock and Position Detection: It must be possible to detect that the cube has been moved, and to distinguish the six different positions.
    - Accelerometer
2. Power Supply: It is only possible to use all six sides of the cube, if there are no cables attached to it.
    - Battery, UPS, Charger
3. Communication: The cube must be able to report context switches to the outside world.
    - WiFi, Server
4. Reporting: The reported times must be stored and visualized.
    - Data Base, Web Interface
5. Configuration: It must be possible to assign up to six projects to the different sides.
    - Configuration File, Web Interface
5. Construction: The cube must be built up.
    - Plywood, Cardboard, or the like

## Devices

The following devices (already purchased) are required to build the _TimeCube_:

1. Raspberry Pi Zero W: Computing device inside the cube
2. Adafruit ADXL335: Accelerometer to track the current position
3. KY-035 Analog Digital Converter: Conversion of accelerometer's signals for the Raspberry Pi's digital inputs
4. PowerBoost 1000 Charger: USP/Charger to operate the cube using a battery and charging it at the same time
5. LiPO Battery 4000mAh: Battery to operate the Raspberry Pi
6. Cables: To interconnect the sensors and devices
7. Plywood, Fretsaw: To build up a sturdy, but light-weight cube prototype

# Evaluation

The best way to test _TimeCube_ is to use it during the working day. The time must be tracked correctly, and switches must be tracked as discrete events. After the working day, the report is to be checked for correctness.

For demonstration purposes, short time spans (minutes or even seconds) will be tracked. These also must be reported correctly, covering the entire time span.

Charging the battery must be possible without disassembling the cube.
