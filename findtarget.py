"""
Looking for a comminication target
"""

from bluetooth import *

target_name = "iPhone"
target_addr = None

nearby_devs = discover_devices()

for address in nearby_devs:
    device_name = lookup_name(address)
    print("Found BT device, address = {}, name = {}".format(address, device_name))
    if target_name == device_name:
        target_addr = address
        break

if target_addr is not None:
    print("Found target BT device, address: {}".format(target_addr))
else:
    print("Could not find target BT device nearby")


