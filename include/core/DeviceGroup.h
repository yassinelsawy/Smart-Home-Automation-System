#pragma once

#include "SmartComponent.h"
#include <vector>
#include <memory>
#include <string>

class DeviceGroup : public SmartComponent {
    string GroupID;
    string GroupName;
public: 
    DeviceGroup();
    DeviceGroup(string gID, string gName); 
    virtual void Add(SmartComponent* component);
    virtual void Remove(SmartComponent* component);
    virtual vector<SmartComponent*> getChildren();
    void turnOn() override;
    void turnOff() override;
    string getName() override;
    string getId() override;
};