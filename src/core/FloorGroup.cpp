#include "../../include/core/FloorGroup.h"
#include "../../include/core/DeviceGroup.h"

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

FloorGroup::FloorGroup() : floorNumber(0) {}

FloorGroup::FloorGroup(string gID, string gName, int fn)
    : DeviceGroup(gID, gName, "Floor"), floorNumber(fn) {}

void FloorGroup::add(SmartComponent* component) {
    DeviceGroup::add(component);
}

void FloorGroup::remove(SmartComponent* component) {
    DeviceGroup::remove(component);
}

vector<SmartComponent*> FloorGroup::getChildren() const {
    return DeviceGroup::getChildren();
}

void FloorGroup::turnOn()  { DeviceGroup::turnOn();  }
void FloorGroup::turnOff() { DeviceGroup::turnOff(); }

string FloorGroup::getName() const {
    return DeviceGroup::getName().empty()
           ? "Floor " + to_string(floorNumber)
           : DeviceGroup::getName();
}

string FloorGroup::getId() const {
    return DeviceGroup::getId().empty()
           ? "FLOOR-" + to_string(floorNumber)
           : DeviceGroup::getId();
}

int FloorGroup::getFloorNumber() const { return floorNumber; }

string FloorGroup::getStatus() const {
    string status = "Floor " + to_string(floorNumber) + ":\n";
    for (auto* child : getChildren())
        status += "  - " + child->getStatus() + "\n";
    return status;
}