#include "../../include/devices/BrandASmartThermoB.h"
#include <iostream>
using namespace std;

BrandASmartThermoB::BrandASmartThermoB(string id, string name, string brand) 
: id(id), name(name), brand(brand){}

void BrandASmartThermoB::setTargetTemperature(double temp) {
    Thermostat::setTargetTemperature(temp);
    cout << "[BrandASmartThermoB] Target set to " << temp << " C\n";
}
double BrandASmartThermoB::getTargetTemperature()  const { return Thermostat::getTargetTemperature(); }
double BrandASmartThermoB::getCurrentTemperature() const { return Thermostat::getCurrentTemperature(); }
void   BrandASmartThermoB::setMode(ThermoMode mode)      { Thermostat::setMode(mode); }
ThermoMode BrandASmartThermoB::getMode()           const { return Thermostat::getMode(); }
