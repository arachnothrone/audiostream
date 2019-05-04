from bluetooth import *

target_name = "iPhone"
target_addr = None

nearby_devs = discover_devices()

for address in nearby_devs:
    print("Found BT dev: {}".format(address))
    if target_name == lookup_name(address):
        target_addr = address
        break

if target_addr is not None:
    print("Found target BT device, address: {}".format(target_addr))
else:
    print("Could not find target BT device nearby")


