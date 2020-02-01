# Requirements

Serial and ZeroMQ:

	sudo apt-get install python3-serial python3-zmq

InfluxDB with cli and Python client:

	sudo apt-get install influx influx-client

# InfluxDB

Create data base:

	influx
	> create database workplace

Select data:

	influx
	> use workplace
	> select * from co2
	> select * from temp
	> select * from humid
	> select * from interrupt
	> select * from wellbeing

Backup data base:
	
	influxd backup -portable -db workplace influx.dump

Restore data base:

	influxd restore -portable -db workplace influx.dump
