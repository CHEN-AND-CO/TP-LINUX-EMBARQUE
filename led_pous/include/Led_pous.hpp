#ifndef LED_POUS_HPP
#define LED_POUS_HPP

#include "GPIO.hpp"

class Led_pous {
    public:
    Led_pous(int led_port, int bp_port): 
        led{led_port, GPIO::OUT},
        boutonPoussoir{bp_port, GPIO::IN}
        {}
    ~Led_pous(){}

    void allume_LED(){ led.set(true); }
    void eteint_LED(){ led.set(false); }

    unsigned int etat_poussoir(){ return boutonPoussoir.get(); }

    private:
    GPIO led, boutonPoussoir;
};

#endif /* LED_POUS_HPP */