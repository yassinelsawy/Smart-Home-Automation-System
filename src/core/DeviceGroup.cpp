#include "SmartComponent.h"
#include "DeviceGroup.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

DeviceGroup::DeviceGroup(string gID, string gName) {
    GroupID = gID;
    GroupName = gName;
}

void DeviceGroup::Add(SmartComponent* component) {
    children.push_back(component);
}

void DeviceGroup::Remove(SmartComponent* component) {
    children.erase(remove(children.begin(), children.end(), component), children.end());
}

vector<SmartComponent*> DeviceGroup::getChildren() {
    return children;
}

void DeviceGroup::turnOn() {
    for (auto* child : children) {
        child->turnOn();
    }
}

void DeviceGroup::turnOff() {
    for (auto* child : children) {
        child->turnOff();
    }
}

string DeviceGroup::getName() {
    return GroupName;
}
string DeviceGroup::getId() {
    return GroupID;
}

string DeviceGroup::getStatus() {
    string status = "Group: " + GroupName + " (ID: " + GroupID + ")\n";
    for (auto* child : children) {
        status += "  - " + child->getStatus() + "\n";
    }
    return status;
}

