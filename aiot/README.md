# TimeCube

_Advanced Internet of Things Project: Group 4_

## Setup and Run

### Raspberry Pi (`timecube`)

A Raspberry Pi Zero W with the following configuration is usesd:

- IP address: `192.168.178.26`
- Username: `pi`
- Password: `raspberry`

Copy the `timecube` folder to the Raspberry Pi built into the TimeCube:

    [user@local]$ scp -r timecube pi@192.168.178.26:/home/pi

Open an SSH connection to the TimeCube:

    [user@local]$ ssh pi@raspberry

Create a virtual environment and install the requirements:

    [pi@raspberry]$ sudo apt-get install python3-venv
    [pi@raspberry]$ cd /home/pi/timecube
    [pi@raspberry]$ python3 -v venv env
    [pi@raspberry]$ source env/bin/activate
    [pi@raspberry]$ pip install -r requirements.txt

Run the application to gather and forward the data, which is both sent over the
ZeroMQ socket and to `stdout`:

    [pi@raspberry]$ ./main.py
    current position: 3
    current position: 3
    current position: 3
    current position: 3
    current position: 6
    current position: 6
    current position: 6

### Mocking the Raspberry Pi (`mockcube`)

In case you don't have a Raspberry Pi with accelerometer and A/D converter at
hand, use the `mockcube` instead.

Switch to the `mockcube` folder, then create and activate a virtual environment:

    [user@local]$ cd src/mockcube
    [user@local]$ python3 -m venv env
    [user@local]$ source env/bin/activate

Install the required packages:

    [user@local]$ pip install -r requirements.txt

Run the application to gather and forward the data, which is both sent over the
ZeroMQ socket and to `stdout`:

    [user@local]$ BIND_ADDRESS=0.0.0.0:5555 ./main.py
    current position: 6
    current position: 6
    current position: 5

### Gateway (`sub_influx`)

To forward the data to InfluxDB, a gateway has to be run (locally, or on any
other system that can open a network connection to the Raspberry Pi). On this
machine, `python3-venv` is also required:

    [user@local]$ cd src/sub_influx
    [user@local]$ python3 -m venv env
    [user@local]$ source env/bin/activate
    [user@local]$ pip -r requirements.txt

The IP address of the Raspberry Pi is needed in order to subscribe from it:

    [user@local]$ SOCK_ADDRESS=192.168.178.26:5555 ./sub_influx.py

The connection to the InfluxDB in the cloud is configured in `config.ini`.

### Web Application (`web_backend`, `web_frontend`)

The web application consists of both a backend, which deals with data access
and aggregation, and a frontend, which serves a minimalistic user interface to
configure the Cube's sides, and to display time tracking reports.

The easiest way to start the web application is through `docker-compose`:

    [user@local]$ cd src/
    [user@local]$ docker-compose up --build

The frontend is served at [http://localhost:8080](http://localhost:8080). The
backend runs on port `8000`, so make sure to keep that port open. Redis is also
provided by the `docker-compose` configuration, so make sure to terminate any
local instances beforehand.
