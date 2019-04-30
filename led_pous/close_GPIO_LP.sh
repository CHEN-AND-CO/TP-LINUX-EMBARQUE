#!/bin/sh

# Init BP
gpio=/sys/class/gpio
bp_num=$((1*32+16))

echo $bp_num > $gpio/unexport