#include "../../include/devices/BrandBSmartThermoA.h"
#include <iostream>
using namespace std;

BrandBSmartThermoA::BrandBSmartThermoA(string id, string name, string brand)
    : id(id), name(name), brand(brand) {}

void BrandBSmartThermoA::setTargetTemperature(double temp) {
    Thermostat::setTargetTemperature(temp);
    cout << "[BrandBSmartThermoA] Target set to " << temp << " C\n";
}
double BrandBSmartThermoA::getTargetTemperature()  const { return Thermostat::getTargetTemperature(); }
double BrandBSmartThermoA::getCurrentTemperature() const { return Thermostat::getCurrentTemperature(); }
void   BrandBSmartThermoA::setMode(ThermoMode mode)      { Thermostat::setMode(mode); }
ThermoMode BrandBSmartThermoA::getMode()           const { return Thermostat::getMode(); }
