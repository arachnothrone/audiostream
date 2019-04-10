# import bluetooth as bt
# # port = bt.PORT_ANY
# port = 13
# print port
# server_sock=bt.BluetoothSocket( bt.RFCOMM )
# server_sock.bind(("",port))
# server_sock.listen(1)
# # bt.advertise_service( server_sock, "Bluetooth Serial Port", service_classes = [bt.HEADSET_CLASS], profiles = [bt.HEADSET_PROFILE])
# bt.advertise_service( server_sock, "Bluetooth Serial Port", service_classes = [bt.SERIAL_PORT_CLASS], profiles = [bt.SERIAL_PORT_PROFILE])
# client_sock, client_info = server_sock.accept()
# print "Accepted connection from ", client_info
# data = client_sock.recv(1024)
# print "received [%s]" % data
# client_sock.close()
# server_sock.close()


# file: rfcomm-server.py
# auth: Albert Huang <albert@csail.mit.edu>
# desc: simple demonstration of a server application that uses RFCOMM sockets
#
# $Id: rfcomm-server.py 518 2007-08-10 07:20:07Z albert $

from bluetooth import *

server_sock=BluetoothSocket( L2CAP )
server_sock.bind(("",PORT_ANY))
server_sock.listen(1)

port = server_sock.getsockname()[1]
print port
#uuid = "94f39d29-7d6d-437d-973b-fba39e49d4ee"
uuid = "00001112-0000-1000-8000-00805f9b34fb"

advertise_service( server_sock, "SampleServer",
                   service_id = uuid,
                   service_classes = [ uuid, HEADSET_CLASS ],
                   profiles = [ HEADSET_PROFILE ], 
#                   protocols = [ OBEX_UUID ] 
                    )
                   
print("Waiting for connection on RFCOMM channel %d" % port)

client_sock, client_info = server_sock.accept()
print("Accepted connection from ", client_info)

try:
    while True:
        data = client_sock.recv(1024)
        if len(data) == 0: break
        print("received [%s]" % data)
except IOError:
    pass

print("disconnected")

client_sock.close()
server_sock.close()
print("all done")
