#include "ADC.hpp"

const std::string ADC::CapeADC_Path = "/sys/devices/ocp.3/helper.14/";

ADC::ADC(std::string device) : value(NULL), dev(device)
{
    
}

ADC::~ADC()
{
    
}

int ADC::read() const {
    std::ifstream _dev(ADC::CapeADC_Path + dev);

    if (!_dev)
    {
        std::cerr << "[CapeADC] Cannot open ADC system file\n\tMake sure Cape devices are correctly initialized beforehand.\n";
    }
    else
    {
        std::string val;
        _dev >> val;
    }

    _dev.close();
}


