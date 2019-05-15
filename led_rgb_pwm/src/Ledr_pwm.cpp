#include "Ledr_pwm.hpp"

Ledr_pwm::Ledr_pwm(std::string device, int period, int polarity): ADC(device) {
    std::ofstream out{ DEVICE_MANAGER_PATH "/slots"};

    out << "am33xx_pwm";
    out.flush();

    out << "bone_pwm_P9_14";
    out.flush();

    setPeriod(period);
    setPolarity(polarity);
}

void Ledr_pwm::setPeriod(int period){
    std::ofstream out{ PWM_PATH "/period"};

    out << period;
    out.flush();
}

int Ledr_pwm::getPeriod(){
    std::ifstream in{ PWM_PATH "/period"};
    int period = 0;

    in >> period;
    
    return period;
}

void Ledr_pwm::setPolarity(int polarity){
    std::ofstream out{ PWM_PATH "/polarity"};

    out << polarity;
    out.flush();
}

void Ledr_pwm::setRun(bool run){
    std::ofstream out{ PWM_PATH "/run"};

    out << ((run)?1:0);
    out.flush();
}

void Ledr_pwm::setDuty(int duty){
    std::ofstream out{ PWM_PATH "/duty"};

    out << duty;
    out.flush();
}

int Ledr_pwm::getDuty(){
    std::ifstream in{ PWM_PATH "/duty"};
    int duty = 0;

    in >> duty;
    
    return duty;
}

void Ledr_pwm::mod_PWM(unsigned int duty){
    setRun(false);
    setDuty(duty);
    setRun(true);
}