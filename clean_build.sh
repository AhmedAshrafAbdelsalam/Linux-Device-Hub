#!/bin/bash 

AvailableDevices=''

for device in "$@"; do
	device=${device:1}
	AvailableDevices+="-D${device^^};"
done

AvailablbeDevices=("${AvailableDevices%?}")

echo ${AvailableDevices}

cd build && rm -rf * && cmake "-DAVAILABLE_DEVICES:STRING=${AvailableDevices}" .. && make
