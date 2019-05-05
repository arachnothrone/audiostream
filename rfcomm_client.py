"""
RFCOMM Client

server addr: B8:27:EB:C6:DB:91
"""

from bluetooth import *

server_address = "B8:27:EB:C6:DB:91"
port = 1

sock = BluetoothSocket(RFCOMM)
sock.connect((server_address, port))

sock.send("qwerty hi")
sock.close()

