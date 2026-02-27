#include "../../include/core/SmartComponent.h"
#include <iostream>
#include <string>
using namespace std;

// Non-pure getStatus defined here (declared const in header)
string SmartComponent::getStatus() const {
    return "Unknown";
}
