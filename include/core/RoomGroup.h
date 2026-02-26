
#include "DeviceGroup.h"
#include "SmartComponent.h"
#include <iostream>
#include <string>
#include <vector>

class RoomGroup : public DeviceGroup {
    string roomType;
public:
    RoomGroup();
    RoomGroup(string rt);
    void Add(SmartComponent* component); 
    void Remove(SmartComponent* component) override;
    vector<SmartComponent*> getChildren() override;
    void turnOn() override;
    void turnOff() override;
    string getName() override;
    string getId() override;
    string getRoomType(){};
    string getStatus() override;
};