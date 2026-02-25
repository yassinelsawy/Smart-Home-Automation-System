#include <iostream>
#include <string>

class SmartDevice;

class IObserver {
public:
    virtual void update(SmartDevice* device) = 0;
};

