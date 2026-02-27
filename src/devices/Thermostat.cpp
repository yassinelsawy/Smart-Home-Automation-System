#include "../../include/devices/Thermostat.h"
#include <iostream>
using namespace std;

Thermostat::Thermostat() 
: m_targetTemp(22.0), m_currentTemp(20.0), m_mode(ThermoMode::AUTO) {}


void Thermostat::setTargetTemperature(double temp) {
    m_targetTemp = temp;
    cout << "[Thermostat] Target temperature set to " << temp << " C\n";
}

double Thermostat::getTargetTemperature() const {
    return m_targetTemp;
}

double Thermostat::getCurrentTemperature() const {
    return m_currentTemp;
}

void Thermostat::setCurrentTemperature(double temp) {
    m_currentTemp = temp;
}

void Thermostat::setMode(ThermoMode mode) {
    m_mode = mode;
}

ThermoMode Thermostat::getMode() const {
    return m_mode;
}
