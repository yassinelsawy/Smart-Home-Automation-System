#include "../../include/core/RoomGroup.h"
#include "../../include/core/DeviceGroup.h"
#include "../../include/core/SmartComponent.h"

#include <vector>
#include <iostream>
#include <string>

using namespace std;

RoomGroup::RoomGroup() {}

RoomGroup::RoomGroup(string gID, string gName, string rt)
    : DeviceGroup(gID, gName, "Room"), roomType(rt) {}

void RoomGroup::add(SmartComponent* component) {
    DeviceGroup::add(component);
}

void RoomGroup::remove(SmartComponent* component) {
    DeviceGroup::remove(component);
}

vector<SmartComponent*> RoomGroup::getChildren() const {
    return DeviceGroup::getChildren();
}

void RoomGroup::turnOn()  { DeviceGroup::turnOn();  }
void RoomGroup::turnOff() { DeviceGroup::turnOff(); }

string RoomGroup::getName() const {
    return DeviceGroup::getName().empty()
           ? "Room: " + roomType
           : DeviceGroup::getName();
}

string RoomGroup::getId() const {
    return DeviceGroup::getId().empty()
           ? "ROOM-" + roomType
           : DeviceGroup::getId();
}

string RoomGroup::getRoomType() const { return roomType; }

string RoomGroup::getStatus() const {
    string status = "Room: " + roomType + ":\n";
    for (auto* child : DeviceGroup::getChildren())
        status += "  - " + child->getStatus() + "\n";
    return status;
}