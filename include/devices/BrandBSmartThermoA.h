#pragma once
#include "Thermostat.h"
#include <string>
using namespace std;

class BrandBSmartThermoA : public Thermostat {
    string id, name, brand;
public:
    BrandBSmartThermoA() = default;
    BrandBSmartThermoA(string id, string name, string brand);

    void setTargetTemperature(double temp)  override;
    double getTargetTemperature() const override;
    double getCurrentTemperature() const override;
    void setMode(ThermoMode mode) override;
    ThermoMode getMode() const override;
};
