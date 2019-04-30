#include <iostream>
#include <chrono>
#include <thread>

#define usleep(x) std::this_thread::sleep_for(std::chrono::microseconds(x))

int main(){
    auto cpt = 0;

    while(true){
        std::cout << "Hello ISEN " << (cpt = (cpt+1)%8) << "\n";

        usleep(1000000);
    }

    return 1;
}