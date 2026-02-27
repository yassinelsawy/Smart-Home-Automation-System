#pragma once
#include "DeviceGroup.h"
#include "SmartComponent.h"
#include <iostream>
#include <string>
#include <vector>

class RoomGroup : public DeviceGroup {
    string roomType;
public:
    RoomGroup();
    RoomGroup(string gID, string gName, string rt);
    void add(SmartComponent* component) override;
    void remove(SmartComponent* component) override;
    vector<SmartComponent*> getChildren() const override;
    void turnOn() override;
    void turnOff() override;
    string getName() const override;
    string getId() const override;
    string getRoomType() const;
    string getStatus() const override;
};