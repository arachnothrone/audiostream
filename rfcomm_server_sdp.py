"""
SDP on RFCOMM server
"""

from bluetooth import *

server_sock=BluetoothSocket(RFCOMM)
server_sock.bind(("", PORT_ANY))
server_sock.listen(1)

advertise_service(server_sock, "SampleServer", service_classes=[SERIAL_PORT_CLASS], profiles=[SERIAL_PORT_PROFILE])
client_sock, client_info = server_sock.accept()
print("Accepted connection from {}".format(client_info))

client_sock.send("PyBluez server: hi")
data = client_sock.recv(1024)
print("Recieved: {}".format(data))

client_sock.close()
server_sock.close()
