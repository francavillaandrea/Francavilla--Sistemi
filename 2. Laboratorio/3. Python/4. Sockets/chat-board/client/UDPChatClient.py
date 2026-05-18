from socket import socket, AF_INET, SOCK_DGRAM
from Message import Message

PORT = 6767

class UDPChatClient:
    def __init__(self, address, name):
        self.clientSocket = socket(AF_INET, SOCK_DGRAM)
        self.address = address
        self.name = name
        self.port = PORT

    def join(self):
        msg = Message(self.name, "")
        self.clientSocket.sendto(msg.serialize(), (self.address, self.port))

    def sendMessage(self, message):
        msg = Message(self.name, message)
        self.clientSocket.sendto(msg.serialize(), (self.address, self.port))

    def leave(self):
        self.clientSocket.close()


