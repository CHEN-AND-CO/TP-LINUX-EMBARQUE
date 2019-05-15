#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <csignal>
#include "Ledr_pwm.hpp"
#include "GPIO.hpp"

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
    GPIO led_blue(GPIO_BLUE, GPIO::OUT), led_green(GPIO_GREEN, GPIO::OUT);

    std::thread led_pwm_red([&lpwm, &mutex](){
        while (true) {
            mutex.lock();
            lpwm.mod_PWM(lpwm.read());
            mutex.unlock();
        }
    });

    std::thread led_pwm_bg([&led_blue, &led_green, &lpwm, &mutex](){
        float tmp = 0.0;

        while (true) {
            led_blue.set(0);
            led_green.set(0);

            mutex.lock();
            tmp = 1000*(1 - lpwm.getDuty()/lpwm.getPeriod());
            std::cout << tmp << std::endl;
            mutex.unlock();

            usleep((int)tmp);

            led_blue.set(1);
            led_green.set(1);

            mutex.lock();
            tmp = 1000*(lpwm.getDuty()/lpwm.getPeriod());
            std::cout << tmp << std::endl;
            mutex.unlock();
            usleep((int)tmp);          
        }
    });

    led_pwm_red.join();
    led_pwm_bg.join();
    
    return 0;
}