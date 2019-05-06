#include <chrono>
#include <thread>
#include <csignal>
#include "Led_pous.hpp"

#define usleep(x) std::this_thread::sleep_for(std::chrono::microseconds(x))

#define LED_ROUGE 1*32+18
#define BOUTON_POUSSOIR 1*32+16

void hInterrupt(int sig) {
    std::cout << "SIGINT (Ctrl+C) caught, exiting...\n";

    exit(sig);
}

int main(){
    //Setting interrupt handler
    signal(SIGINT, hInterrupt);

    Led_pous board(LED_ROUGE, BOUTON_POUSSOIR);

    while(true){
        if(board.etat_poussoir()){
            board.allume_LED();
        }else{
            board.eteint_LED();
        }

        usleep(100000);
    }

    return 0;
}