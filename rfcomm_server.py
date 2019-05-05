"""
RFCOMM server
"""

from bluetooth import *

port = 1
backlog = 1

server_sock = BluetoothSocket(RFCOMM)
server_sock.bind(("", port))
server_sock.listen(backlog)

client_sock, client_info = server_sock.accept()
print("Accepted connection from: {}".format(client_info))

data = client_sock.recv(1024)
print("Received: {}".format(data))

client_sock.close()
server_sock.close()


