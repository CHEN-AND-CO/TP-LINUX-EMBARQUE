#include <iostream>
#include <chrono>
#include <thread>
#include <csignal>

#define usleep(x) std::this_thread::sleep_for(std::chrono::microseconds(x))


void hInterrupt(int sig) {
    std::cout << "SIGINT (Ctrl+C) caught, exiting...\n";

    exit(sig);
}

int main(){
    //Setting interrupt handler
    signal(SIGINT, hInterrupt);
    
    

    return 0;
}