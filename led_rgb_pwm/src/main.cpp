#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
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
    
    std::mutex mutex;
    Ledr_pwm lpwm("AIN3");

    std::thread led_pwm_red([&lpwm, &mutex](){
        while (true) {
            mutex.lock();
            lpwm.mod_PWM(lpwm.read());
            mutex.unlock();
        }
    });

    std::thread led_pwm_bg([&lpwm, &mutex](){
        while (true) {
            mutex.lock();

            mutex.unlock();
        }
    });

    led_pwm_red.join();
    

    return 0;
}