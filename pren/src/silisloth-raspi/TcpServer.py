import socket

import Log


class TcpServer:

    def __init__(self):
        self.ip = '0.0.0.0'
        self.port = 7777
        self.buf_size = 1024
        self.logger = Log.instance('TcpServer')

        try:
            self.server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.server.bind((self.ip, self.port))
            self.server.listen(5)
            self.logger.info("TCP Server waits for client to connect")
            self.client, _ = self.server.accept()
            self.logger.info("TCP Server is connected with client")

        except Exception as e:
            self.logger.debug(e)
            self.server.close()

    def close(self):
        self.server.close()
        self.logger.info("TCP Server is closed")

    def send(self, message):
        self.logger.debug("Send message to client: {}".format(message))
        self.client.send(message)

    def receive(self):
        data = self.client.recv(self.buf_size)
        receivedMessage = data.decode('utf-8')
        self.logger.debug(
            "Received message from client: {}".format(receivedMessage))
        return receivedMessage
