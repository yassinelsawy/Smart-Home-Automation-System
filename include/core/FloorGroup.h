#pragma once

#include "DeviceGroup.h"
#include <string>


class FloorGroup : public DeviceGroup {
    int floorNumber;
public:
    FloorGroup();
    FloorGroup(string gID, string gName, int fn);
    void add(SmartComponent* component) override;
    void remove(SmartComponent* component) override;
    vector<SmartComponent*> getChildren() const override;
    void turnOn() override;
    void turnOff() override;
    string getName() const override;
    string getId() const override;
    string getStatus() const override;
    int getFloorNumber() const;
};
