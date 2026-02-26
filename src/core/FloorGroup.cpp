#include "FloorGroup.h"
#include "DeviceGroup.h"

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

FloorGroup::FloorGroup(int fn) {
    floorNumber = fn;
}

void FloorGroup::Add(SmartComponent* component) {
    DeviceGroup::Add(component);
}

void FloorGroup::Remove(SmartComponent* component) {
    DeviceGroup::Remove(component);
}

vector<SmartComponent*> FloorGroup::getChildren() {
    return DeviceGroup::getChildren();
}

void FloorGroup::turnOn() {
    DeviceGroup::turnOn();
}

void FloorGroup::turnOff() {
    DeviceGroup::turnOff();
}

string FloorGroup::getName() {
    return "Floor " + to_string(floorNumber);
}

string FloorGroup::getId() {
    return "FLOOR-" + to_string(floorNumber);
}

string FloorGroup::getStatus() {
    string status = "Floor " + to_string(floorNumber) + ":\n";
    for (auto* child : getChildren()) {
        status += "  - " + child->getStatus() + "\n";
    }
    return status;
}