
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;


class SmartComponent {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual string getName() = 0;
    virtual string getId() = 0;
    virtual string getStatus() = 0;
    virtual ~SmartComponent() = default;
};


