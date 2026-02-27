#include "../../include/devices/DoorLock.h"
#include <iostream>
using namespace std;

void DoorLock::lock() {
    m_locked = true;
    cout << "[DoorLock] Door is now LOCKED.\n";
}

void DoorLock::unlock() {
    m_locked = false;
    cout << "[DoorLock] Door is now UNLOCKED.\n";
}

bool DoorLock::isLocked() const {
    return m_locked;
}

void DoorLock::setPin(const string& pin) {
    m_pin = pin;
}
