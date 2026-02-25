/**
 * @file test_observer.cpp
 * @brief Unit tests for Observer Pattern (MotionSensor, Camera, AlertSystem).
 */

#include "../include/devices/MotionSensor.h"
#include "../include/devices/Camera.h"
#include "../include/observer/AlertSystem.h"
#include "../include/observer/EventManager.h"

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

void testMotionSensorNotifiesObserver() {
    auto sensor = std::make_shared<Devices::MotionSensor>("PIR1", "S001", "Hall");
    auto alerts = std::make_shared<Observer::AlertSystem>("SecurityPanel");

    sensor->attach(alerts);
    sensor->turnOn();
    sensor->triggerMotion();

    TEST("AlertSystem received 1 event", alerts->alertCount() == 1);
}

void testDetachStopsNotification() {
    auto sensor = std::make_shared<Devices::MotionSensor>("PIR2", "S002", "Porch");
    auto alerts = std::make_shared<Observer::AlertSystem>("Panel2");

    sensor->attach(alerts);
    sensor->detach(alerts);
    sensor->turnOn();
    sensor->triggerMotion();

    TEST("AlertSystem received 0 events after detach", alerts->alertCount() == 0);
}

void testEventManagerPublish() {
    auto mgr    = Observer::EventManager{};
    auto alerts = std::make_shared<Observer::AlertSystem>("EventBusPanel");

    mgr.subscribe("motion", alerts);
    mgr.publish("motion", "PIR3", "MOTION_DETECTED");

    TEST("EventManager dispatched event to subscriber", alerts->alertCount() == 1);
}

void testCameraMotionNotification() {
    auto cam    = std::make_shared<Devices::Camera>("Cam1", "C001", "Front Door");
    auto alerts = std::make_shared<Observer::AlertSystem>("CamPanel");

    cam->attach(alerts);
    cam->turnOn();
    cam->detectMotion();

    TEST("Camera notified alert on motion detect", alerts->alertCount() == 1);
}

int main() {
    std::cout << "=== Observer Pattern Tests ===\n";
    testMotionSensorNotifiesObserver();
    testDetachStopsNotification();
    testEventManagerPublish();
    testCameraMotionNotification();
    std::cout << "\nResults: " << g_passed << " passed, " << g_failed << " failed.\n";
    return g_failed == 0 ? 0 : 1;
}
