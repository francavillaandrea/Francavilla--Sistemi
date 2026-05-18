from socket import socket, AF_INET, SOCK_DGRAM
from Message import Message
import threading

PORT = 6767
BUFFER_SIZE = 2048

class UDPChatServer:
    def __init__(self):
        self.serverSocket = socket(AF_INET, SOCK_DGRAM)
        self.clients = {}  # {address: name}
        self.running = True

    def stop(self):
        self.running = False
        self.serverSocket.close()
        print("Server stoppato.")
        print("ARRIVEDERCI")

    def start(self):
        self.serverSocket.bind(("0.0.0.0", PORT))
        print("Server partito e in ascolto...")
        self.serverMain()

    def serverMain(self):
        try:
            while self.running:
                data_bytes, address = self.serverSocket.recvfrom(BUFFER_SIZE)

                try:
                    msg = Message.deserialize(data_bytes)
                except:
                    continue

                if address not in self.clients:
                    # Nuovo client si registra
                    self.clients[address] = msg.name
                    print(f"{msg.name} joins the chat")
                else:
                    # Client invia messaggio
                    print(f"> {msg.name}: {msg.content}")
        except Exception as e:
            if self.running:
                print(f"err: {e}")
        finally:
            self.stop()







