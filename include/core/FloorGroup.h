#pragma once

#include "DeviceGroup.h"
#include <string>


class FloorGroup : public DeviceGroup {
    int floorNumber;
public:
    FloorGroup();
    FloorGroup(int fn);
    void Add(SmartComponent* component) override;
    void Remove(SmartComponent* component) override;
    vector<SmartComponent*> getChildren() override;
    void turnOn() override;
    void turnOff() override;
    string getName() override;
    string getId() override;
};
