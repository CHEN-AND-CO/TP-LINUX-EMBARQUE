#include <iostream>
#include <chrono>
#include <thread>
#include <csignal>
#include "Ledr_pwm.hpp"

#define usleep(x) std::this_thread::sleep_for(std::chrono::microseconds(x))

#define GPIO_RED 1 * 32 + 18
#define GPIO_GREEN 1 * 32 + 28
#define GPIO_BLUE 3


void hInterrupt(int sig) {
    std::cout << "SIGINT (Ctrl+C) caught, exiting...\n";

    exit(sig);
}

int main(){
    //Setting interrupt handler
    signal(SIGINT, hInterrupt);
    
    Ledr_pwm lpwm("AIN3");

    while (true) {
        lpwm.mod_PWM(lpwm.read());

        //usleep(500000);
    }

    return 0;
}