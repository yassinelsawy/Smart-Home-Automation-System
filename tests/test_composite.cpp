/**
 * @file test_composite.cpp
 * @brief Unit tests for the Composite Pattern (SmartComponent hierarchy).
 *
 * Uses a simple hand-rolled test harness (no external framework)
 * so the project has zero test dependencies.
 */

#include "../include/core/DeviceGroup.h"
#include "../include/core/RoomGroup.h"
#include "../include/core/FloorGroup.h"
#include "../include/devices/Light.h"
#include "../include/devices/Thermostat.h"

#include <cassert>
#include <iostream>
#include <memory>

using namespace SmartHome;

static int g_passed = 0;
static int g_failed = 0;

#define TEST(name, expr) \
    do { \
        if (expr) { std::cout << "[PASS] " name "\n"; ++g_passed; } \
        else      { std::cout << "[FAIL] " name "\n"; ++g_failed; } \
    } while(0)

void testDeviceGroupChildCount() {
    auto room  = std::make_shared<Core::RoomGroup>("Living Room", "Lounge", 1);
    auto light = std::make_shared<Devices::Light>("Ceiling Light", "L001", "Living Room");
    auto therm = std::make_shared<Devices::Thermostat>("Wall Therm", "T001", "Living Room");

    TEST("Initial child count is 0", room->childCount() == 0);
    room->add(light);
    TEST("Child count is 1 after add", room->childCount() == 1);
    room->add(therm);
    TEST("Child count is 2 after second add", room->childCount() == 2);
    room->remove(light);
    TEST("Child count is 1 after remove", room->childCount() == 1);
}

void testLeafIsNotComposite() {
    auto light = std::make_shared<Devices::Light>("L", "L999", "Hall");
    TEST("Leaf Light is not composite", !light->isComposite());
}

void testGroupIsComposite() {
    auto group = std::make_shared<Core::DeviceGroup>("Group");
    TEST("DeviceGroup is composite", group->isComposite());
}

void testTurnOnPropagates() {
    auto floor = std::make_shared<Core::FloorGroup>("Floor 1", 1);
    auto room  = std::make_shared<Core::RoomGroup>("Bedroom", "Bedroom", 1);
    auto light = std::make_shared<Devices::Light>("Bedside", "L002", "Bedroom");

    room->add(light);
    floor->add(room);
    floor->turnOn();

    TEST("Light is enabled after floor.turnOn()", light->isEnabled());
}

void testTurnOffPropagates() {
    auto group = std::make_shared<Core::DeviceGroup>("grp");
    auto light = std::make_shared<Devices::Light>("L", "L003", "Hall");
    group->add(light);
    group->turnOn();
    group->turnOff();
    TEST("Light is disabled after group.turnOff()", !light->isEnabled());
}

int main() {
    std::cout << "=== Composite Pattern Tests ===\n";
    testDeviceGroupChildCount();
    testLeafIsNotComposite();
    testGroupIsComposite();
    testTurnOnPropagates();
    testTurnOffPropagates();
    std::cout << "\nResults: " << g_passed << " passed, " << g_failed << " failed.\n";
    return g_failed == 0 ? 0 : 1;
}
