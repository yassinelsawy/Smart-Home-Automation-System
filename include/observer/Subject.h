#pragma once
#include <string>
#include "Observer.h"

class Subject {
public:
    virtual void attach(Observer* o) = 0;
    virtual void detach(Observer* o) = 0;
    virtual void notify() = 0;
    virtual ~Subject() = default;
};

