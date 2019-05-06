#!/bin/sh

cd /sys/devices/bone_capemgr.*

echo am33xx_pwm > slots

echo bone_pwm_P9_14 > slots

echo 1800000000 > /sys/devices/ocp.3/pwm_test_P9_14.15/period

echo 0 > /sys/devices/ocp.3/pwm_test_P9_14.15/polarity

echo 0 > /sys/devices/ocp.3/pwm_test_P9_14.15/run

echo 900000000 > /sys/devices/ocp.3/pwm_test_P9_14.15/duty

echo 1 > /sys/devices/ocp.3/pwm_test_P9_14.15/run