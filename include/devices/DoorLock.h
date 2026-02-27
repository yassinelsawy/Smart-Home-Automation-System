#pragma once

#include <string>
using namespace std;

class DoorLock {
    bool   m_locked = false;
    string m_pin;
public:
    DoorLock() = default;
    virtual ~DoorLock() = default;

    void lock();
    void unlock();
    bool isLocked() const;
    void setPin(const string& pin);
};
