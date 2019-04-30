#include "Led_pous.hpp"

#define usleep(x) std::this_thread::sleep_for(std::chrono::microseconds(x))

#define LED_ROUGE 1*32+18
#define BOUTON_POUSSOIR 1*32+16

int main(){
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