#include "../../include/core/SmartDevice.h"
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

SmartDevice::SmartDevice(string i, string n, string b)
    : id(i), name(n), brand(b), currentState(nullptr)
{
    DeviceStatus = "Off";
}

void SmartDevice::turnOn() {
    if (currentState) {
        currentState->turnOn(this);
        DeviceStatus = currentState->getStateName();
    } else {
        DeviceStatus = "On";
    }
    notify();
}

void SmartDevice::turnOff() {
    if (currentState) {
        currentState->turnOff(this);
        DeviceStatus = currentState->getStateName();
    } else {
        DeviceStatus = "Off";
    }
    notify();
}

void SmartDevice::dim(int level) {
    if (currentState) {
        currentState->dim(this, level);
        DeviceStatus = currentState->getStateName();
    } else {
        DeviceStatus = "Dimmed";
    }
    notify();
}

string SmartDevice::getName() const { return name; }
string SmartDevice::getId()   const { return id;   }
string SmartDevice::getStatus() const { return DeviceStatus; }

void SmartDevice::setLocation(string l) { location = l; }

void SmartDevice::attach(Observer* o) {
    observers.push_back(o);
}

void SmartDevice::detach(Observer* o) {
    observers.erase(remove(observers.begin(), observers.end(), o), observers.end());
}

void SmartDevice::notify() {
    for (auto* obs : observers)
        obs->update(this);
}
