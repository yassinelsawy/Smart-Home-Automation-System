#include "../../include/core/SmartComponent.h"
#include "../../include/core/DeviceGroup.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

DeviceGroup::DeviceGroup() {}

DeviceGroup::DeviceGroup(string gID, string gName, string gType)
    : groupId(gID), groupName(gName), groupType(gType) {}

void DeviceGroup::add(SmartComponent* component) {
    children.push_back(component);
}

void DeviceGroup::remove(SmartComponent* component) {
    children.erase(std::remove(children.begin(), children.end(), component), children.end());
}

vector<SmartComponent*> DeviceGroup::getChildren() const {
    return children;
}

void DeviceGroup::turnOn() {
    for (auto* child : children)
        child->turnOn();
}

void DeviceGroup::turnOff() {
    for (auto* child : children)
        child->turnOff();
}

string DeviceGroup::getName() const { return groupName; }
string DeviceGroup::getId()   const { return groupId; }
string DeviceGroup::getGroupType() const { return groupType; }

string DeviceGroup::getStatus() const {
    string status = "Group: " + groupName + " (ID: " + groupId + ")\n";
    for (auto* child : children)
        status += "  - " + child->getStatus() + "\n";
    return status;
}


