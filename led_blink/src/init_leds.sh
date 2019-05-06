#!/bin/bash

# Init LEDs
gpio=/sys/class/gpio
#gpio_id=$((1*32+28))

function gpio_init {
        echo init port $1
        echo $1 > $gpio/export
        echo "set mode " $2
        echo $2 > $gpio/gpio$1/direction
}

gpio_init $((1*32+18)) out      # Red
gpio_init $((1*32+28)) out      # Green
gpio_init 3 out                 # Blue
