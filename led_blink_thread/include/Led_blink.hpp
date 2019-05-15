#ifndef LED_BLINK_HPP
#define LED_BLINK_HPP

#include "GPIO.hpp"

class Led_blink : public GPIO {
    public:
    Led_blink(int port): GPIO(port, GPIO::OUT){}

    void permut_LED(){ this->set(!this->get()); }
    private:
};

#endif /* LED_BLINK_HPP */