"""
Looking for a comminication target
"""

from bluetooth import *
import time

target_name = "iPhone"
target_addr = None

t1 = time.time()
nearby_devs = discover_devices(duration=7, flush_cache=True)

for address in nearby_devs:
    device_name = lookup_name(address, timeout=6)
    print("Found BT device, address = {}, name = {}".format(address, device_name))
    if target_name == device_name:
        target_addr = address
        break

t2 = time.time()

if target_addr is not None:
    print("Found target BT device, address: {}".format(target_addr))
else:
    print("Could not find target BT device nearby")

print("Discovery time: {}".format(time.strftime("%H:%M:%S", time.gmtime(t2-t1))))


#>>> time.strftime("%H:%M:%S", time.gmtime(666))
#'00:11:06'
#>>> time.strftime("%H:%M:%S", 443)
#Traceback (most recent call last):
#      File "<stdin>", line 1, in <module>
#      TypeError: argument must be 9-item sequence, not int
#      >>> time.gmtime(11)
#      time.struct_time(tm_year=1970, tm_mon=1, tm_mday=1, tm_hour=0, tm_min=0, tm_sec=11, tm_wday=3, tm_yday=1, tm_isdst=0)
#      >>> t1 = time.time()
#      >>> t2 = time.time()
#      >>> t2-t1
#      6.108670949935913
#      >>> time.strftime("%H:%M:%S", time.gmtime(t2-t1))
#      '00:00:06'
#
