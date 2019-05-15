#include <iostream>
#include <chrono>
#include <thread>
#include <csignal>

#include "ADC.hpp"

#define usleep(x) std::this_thread::sleep_for(std::chrono::microseconds(x))
#define sleep(x) usleep(x*1000)

void hInterrupt(int sig) {
    std::cout << "SIGINT (Ctrl+C) caught, exiting...\n";

    exit(sig);
}

int main(){
    //Setting interrupt handler
    signal(SIGINT, hInterrupt);
    
    ADC analogIn("AIN3");


    while (true)
    {
        sleep(100);
        std::cout << "Analog value : " << analogIn.read() << "\r";
    }

    
    return 0;
}