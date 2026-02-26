#include "SmartDevice.h"
#include "SmartComponent.h"
#include "ISubject.h"
#include "IDeviceState.h"
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

SmartDevice::SmartDevice(string i, string n, string b) : id(i), name(n), brand(b){
    DeviceStatus = currentState->getStatus();
}

void SmartDevice::turnOn() {
    if (currentState) {
        currentState->turnOn();
        DeviceStatus = currentState->getStatus();
        notify();
    }
}

void SmartDevice::turnOff() {
    if (currentState) {
        currentState->turnOff();
        DeviceStatus = currentState->getStatus();
        notify();
    }
}

string SmartDevice::getName() {
    return name;
}

string SmartDevice::getId() {
    return id;
}

string SmartDevice::getStatus() {
    return DeviceStatus;
}

void SmartDevice::setLocation(string l) {
    location = l;
}

void SmartDevice::attach(IObserver* o) {
    observers.push_back(o);
}

void SmartDevice::detach(IObserver* o) {
    observers.erase(remove(observers.begin(), observers.end(), o), observers.end());
}

void SmartDevice::notify() {
    for (auto* observer : observers) {
        observer->update(this);
    }
}

