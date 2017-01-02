#!/bin/bash
make clean
make udp-server TARGET=z1
make udp-server.upload MOTES=/dev/ttyUSB0
make login MOTES=/dev/ttyUSB0
