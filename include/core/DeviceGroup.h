#pragma once

#include "SmartComponent.h"
#include <vector>
#include <memory>
#include <string>

class DeviceGroup : public SmartComponent {
    string groupId;
    string groupName;
    string groupType;
    vector<SmartComponent*> children;
public: 
    DeviceGroup();
    DeviceGroup(string gID, string gName, string gType = "Generic"); 
    virtual void add(SmartComponent* component);
    virtual void remove(SmartComponent* component);
    virtual vector<SmartComponent*> getChildren() const;
    void turnOn() override;
    void turnOff() override;
    string getStatus() const override;
    string getName() const override;
    string getId() const override;
    string getGroupType() const;
};