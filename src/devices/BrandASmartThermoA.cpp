#include "../../include/devices/BrandASmartThermoA.h"
#include <iostream>
using namespace std;

BrandASmartThermoA::BrandASmartThermoA(string id, string name, string brand) 
    : id(id), name(name), brand(brand){}

void BrandASmartThermoA::setTargetTemperature(double temp) {
    Thermostat::setTargetTemperature(temp);
    cout << "[BrandASmartThermoA] Target set to " << temp << " C\n";
}
double BrandASmartThermoA::getTargetTemperature()  const { return Thermostat::getTargetTemperature(); }
double BrandASmartThermoA::getCurrentTemperature() const { return Thermostat::getCurrentTemperature(); }
void   BrandASmartThermoA::setMode(ThermoMode mode) { Thermostat::setMode(mode); }
ThermoMode BrandASmartThermoA::getMode() const { return Thermostat::getMode(); }
