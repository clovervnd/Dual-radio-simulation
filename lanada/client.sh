#!/bin/bash
make clean
make udp-client
make udp-client.upload MOTES=/dev/ttyUSB1
make login MOTES=/dev/ttyUSB1
