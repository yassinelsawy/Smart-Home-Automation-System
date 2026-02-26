#pragma once

#include "../core/SmartDevice.h"
#include "../state/IDeviceState.h"
#include <memory>
#include <string>


class Thermostat {
public:
    Thermostat(){}
    Thermostat(string type){}
    virtual ~Thermostat() = default;
    void setTemperature(double temp) const;
    double getTemperature() const;

};
