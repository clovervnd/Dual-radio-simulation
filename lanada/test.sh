#!/bin/bash
make clean TARGET=zoul BOARD=firefly
#make udp-client TARGET=zoul BOARD=firefly
make udp-client TARGET=zoul BOARD= firefly 
make udp-client.upload MOTES=/dev/ttyUSB0
make login MOTES=/dev/ttyUSB0
