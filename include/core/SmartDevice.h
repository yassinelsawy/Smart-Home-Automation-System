
#pragma once
#include "SmartComponent.h"
#include "../observer/Observer.h"
#include "../observer/Subject.h"
#include "../state/IDeviceState.h"
#include <string>
#include <vector>
using namespace std;

class SmartDevice : public SmartComponent, public Subject {
    string id, name, brand, DeviceStatus, location;
    vector<Observer*> observers;
    IDeviceState* currentState;
public:
    SmartDevice(string i, string n, string b);
    void turnOn() override;
    void turnOff() override;
    void dim(int level);
    string getName() const override;
    string getId() const override;
    string getStatus() const override;
    void setLocation(string l);
    void attach(Observer* o) override;
    void detach(Observer* o) override;
    void notify() override;
};