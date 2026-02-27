#include "../../include/devices/BrandBSmartThermoB.h"
#include <iostream>
using namespace std;

BrandBSmartThermoB::BrandBSmartThermoB(string id, string name, string brand)
    : id(id), name(name), brand(brand) {}

void BrandBSmartThermoB::setTargetTemperature(double temp) {
    Thermostat::setTargetTemperature(temp);
    cout << "[BrandBSmartThermoB] Target set to " << temp << " C\n";
}
double BrandBSmartThermoB::getTargetTemperature()  const { return Thermostat::getTargetTemperature(); }
double BrandBSmartThermoB::getCurrentTemperature() const { return Thermostat::getCurrentTemperature(); }
void   BrandBSmartThermoB::setMode(ThermoMode mode)      { Thermostat::setMode(mode); }
ThermoMode BrandBSmartThermoB::getMode()           const { return Thermostat::getMode(); }
