#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class SmartComponent {
public:
    virtual void turnOn()  = 0;
    virtual void turnOff() = 0;
    virtual string getName() const = 0;
    virtual string getId() const = 0;
    virtual string getStatus() const;
    virtual ~SmartComponent() = default;
};
