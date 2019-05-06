#include <iostream>
#include <chrono>
#include <thread>
#include <csignal>
#include "Led_blink.hpp"

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
    
    Led_blink aled(GPIO_GREEN);

    std::thread led_blink_thread([&aled](){
            while(true){
                aled.permut_LED();
                usleep(500000);
            }
        }
    );

    led_blink_thread.join();

    return 0;
}