from bluetooth import *

port = 0x1001
backlog = 1

server_sock = BluetoothSocket(L2CAP)
server_sock.bind(("", port))
server_sock.listen(backlog)

client_sock, address = server_sock.accept()
print("Accepted connection from {}".format(address))

data = client_sock.recv(1024)
print("Received {}".format(data))

client_sock.close()
server_sock.close()

