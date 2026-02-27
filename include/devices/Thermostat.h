#pragma once

#include <string>
using namespace std;

enum class ThermoMode { COOLING, HEATING, AUTO };

class Thermostat {
    double m_targetTemp;
    double m_currentTemp;
    ThermoMode m_mode;
public:
    Thermostat();
    // Thermostat(string type) {}
    virtual ~Thermostat() = default;

    virtual void setTargetTemperature(double temp);
    virtual double getTargetTemperature() const;
    virtual double getCurrentTemperature() const;
    virtual void setCurrentTemperature(double temp);
    virtual void setMode(ThermoMode mode);
    virtual ThermoMode getMode() const;
};
