#include <iostream>
#include <chrono>
#include <thread>
#include "Led_blink.hpp"

#define usleep(x) std::this_thread::sleep_for(std::chrono::microseconds(x))

#define GPIO_RED 1 * 32 + 18
#define GPIO_GREEN 1 * 32 + 28
#define GPIO_BLUE 3

int main(){
    Led_blink aled(GPIO_GREEN);
    int compteur = 0;


    while (compteur++ < 20) {
        aled.permut_LED();
        usleep(500000);
    }

    return 0;
}