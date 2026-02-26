#include "RoomGroup.h"
#include "DeviceGroup.h"
#include "SmartComponent.h"

#include <vector>
#include <iostream>
#include <string>

using namespace std;

RoomGroup::RoomGroup(string rt) {
    roomType = rt;
}

void RoomGroup::Add(SmartComponent* component) {
    DeviceGroup::Add(component);
}

void RoomGroup::Remove(SmartComponent* component) {
    DeviceGroup::Remove(component);
}

vector<SmartComponent*> RoomGroup::getChildren() {
    return DeviceGroup::getChildren();
}

void RoomGroup::turnOn() {
    DeviceGroup::turnOn();
}

void RoomGroup::turnOff() {
    DeviceGroup::turnOff();
}

string RoomGroup::getName() {
    return "Room: " + roomType;
}

string RoomGroup::getId() {
    return "ROOM-" + roomType;
}

string RoomGroup::getStatus() {
    string status = "Room: " + roomType + ":\n";
    for (auto* child : getChildren()) {
        status += "  - " + child->getStatus() + "\n";
    }
    return status;
}