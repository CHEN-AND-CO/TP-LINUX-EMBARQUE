#ifndef LEDR_PWM_HPP
#define LEDR_PWM_HPP

#include "ADC.hpp"

#define DEVICE_MANAGER_PATH "/sys/devices/bone_capemgr.9"
#define PWM_PATH "/sys/devices/ocp.3/pwm_test_P9_14.15"

class Ledr_pwm : public ADC {
    public:
    Ledr_pwm(std::string device, int period = 1800, int polarity = 0);

    void setPeriod(int period);
    void setPolarity(int polarity);
    void setRun(bool run);
    void setDuty(int duty);

    void mod_PWM(unsigned int duty);
    private:

};

#endif /* LEDR_PWM_HPP */