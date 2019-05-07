from bluetooth import *

server_addr = ""
port = 0x1001

sock = BluetoothSocket(L2CAP)
sock.connect((server_addr, port))

sock.send("hello!!!")
sock.close()

