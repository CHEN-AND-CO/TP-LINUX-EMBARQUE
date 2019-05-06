
#include <iostream>
#include <chrono>
#include <thread>
#include "GPIO.hpp"

#define usleep(x) std::this_thread::sleep_for(std::chrono::microseconds(x))

#define GPIO_RED 1 * 32 + 18
#define GPIO_GREEN 1 * 32 + 28
#define GPIO_BLUE 3

int main(int argc, char *argv[])
{
    GPIO led_red(GPIO_RED, GPIO::OUT);

    while (true) {
        led_red.set(true);
        usleep(1000*1000);
        led_red.set(false);
        usleep(1000 * 1000);
    }

    return 0;
}