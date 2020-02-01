# ZeroMQ
port = 5555
sock = 'tcp://localhost:{:d}'.format(port)
bind = 'tcp://0.0.0.0:{:d}'.format(port)

reply_ack = b'ack'
reply_err = b'err'

# InfluxDB
influx_host = 'localhost'
influx_port = 8086
influx_db = 'workplace'
