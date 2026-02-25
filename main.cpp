/**
 * @file main.cpp
 * @brief Smart Home Automation System – demonstration entry point.
 *
 * Demonstrates:
 *  1. Abstract Factory  – device creation via BasicDeviceFactory
 *  2. Composite         – FloorGroup → RoomGroup → Device hierarchy
 *  3. Command           – TurnOn/Off, SetTemperature, macro batch, undo
 *  4. Observer          – AlertSystem subscribed to motion sensors & cameras
 *  5. State             – Light transitions (Inactive → Active)
 *  6. Strategy          – Security & Comfort automation modes
 *  7. Adapter           – LegacyDevice integrated via LegacyDeviceAdapter
 */

#include "include/core/SmartHomeHub.h"
#include "include/core/FloorGroup.h"
#include "include/core/RoomGroup.h"

#include "include/devices/Light.h"
#include "include/devices/Thermostat.h"
#include "include/devices/Camera.h"
#include "include/devices/MotionSensor.h"
#include "include/devices/DoorLock.h"

#include "include/command/CommandInvoker.h"
#include "include/command/TurnOnCommand.h"
#include "include/command/TurnOffCommand.h"
#include "include/command/SetTemperatureCommand.h"

#include "include/observer/AlertSystem.h"
#include "include/observer/EventManager.h"

#include "include/state/ActiveState.h"
#include "include/state/StandbyState.h"
#include "include/state/InactiveState.h"

#include "include/strategy/SecurityStrategy.h"
#include "include/strategy/ComfortStrategy.h"
#include "include/strategy/EnergyEfficiencyStrategy.h"

#include "include/factory/BasicDeviceFactory.h"
#include "include/factory/PremiumDeviceFactory.h"

#include "include/adapter/LegacyDevice.h"
#include "include/adapter/LegacyDeviceAdapter.h"

#include "include/utils/Logger.h"
#include "include/utils/Timer.h"

#include <iostream>
#include <memory>

// ─────────────────────────────────────────────────────────────────────────────

void printSectionHeader(const std::string& title) {
    std::cout << "\n";
    std::cout << "╔══════════════════════════════════════════╗\n";
    std::cout << "║  " << title;
    std::cout << std::string(41 - title.size(), ' ') << "║\n";
    std::cout << "╚══════════════════════════════════════════╝\n";
}

// ─────────────────────────────────────────────────────────────────────────────

int main() {
    // ── Configure logger ────────────────────────────────────────────────────
    using namespace SmartHome;
    Utils::Logger::instance().setMinLevel(Utils::LogLevel::INFO);
    // Optional: Utils::Logger::instance().setLogFile("smarthome.log");

    Utils::Timer totalTimer;
    totalTimer.start();

    // ████████████████████████████████████████████████████████████████████████
    // 1. ABSTRACT FACTORY – Create devices for each room
    // ████████████████████████████████████████████████████████████████████████
    printSectionHeader("1. Abstract Factory Pattern");

    Factory::BasicDeviceFactory   basicFactory;
    Factory::PremiumDeviceFactory premiumFactory;

    std::cout << "Using factory: " << basicFactory.getFactoryName()   << "\n";
    std::cout << "Using factory: " << premiumFactory.getFactoryName() << "\n";

    // Ground-floor living room devices (basic tier)
    auto livingLight  = basicFactory.createLight      ("Living Room Light", "L001", "Living Room");
    auto livingTherm  = basicFactory.createThermostat ("Living Room Therm", "T001", "Living Room");
    auto frontCamera  = basicFactory.createCamera     ("Front Door Cam",    "C001", "Front Door");
    auto hallSensor   = basicFactory.createMotionSensor("Hall Motion Sensor","S001", "Hallway");
    auto frontLock    = basicFactory.createDoorLock   ("Front Door Lock",   "DL001","Front Door");

    // Bedroom devices (premium tier)
    auto bedLight     = premiumFactory.createLight    ("Bedroom Light",     "L002", "Bedroom");
    auto bedTherm     = premiumFactory.createThermostat("Bedroom Therm",     "T002", "Bedroom");

    // ████████████████████████████████████████████████████████████████████████
    // 2. COMPOSITE – Build the device tree
    // ████████████████████████████████████████████████████████████████████████
    printSectionHeader("2. Composite Pattern");

    auto hub = std::make_shared<Core::SmartHomeHub>("My Smart Home");

    // Ground Floor
    auto ground = std::make_shared<Core::FloorGroup>("Ground Floor", 0);

    auto livingRoom = std::make_shared<Core::RoomGroup>("Living Room", "Lounge", 0);
    livingRoom->add(livingLight);
    livingRoom->add(livingTherm);

    auto hallway = std::make_shared<Core::RoomGroup>("Hallway", "Corridor", 0);
    hallway->add(hallSensor);
    hallway->add(frontCamera);
    hallway->add(frontLock);

    ground->add(livingRoom);
    ground->add(hallway);

    // First Floor
    auto first = std::make_shared<Core::FloorGroup>("First Floor", 1);
    auto bedroom = std::make_shared<Core::RoomGroup>("Bedroom", "Bedroom", 1);
    bedroom->add(bedLight);
    bedroom->add(bedTherm);
    first->add(bedroom);

    hub->add(ground);
    hub->add(first);

    std::cout << "\nDevice hierarchy:\n";
    hub->getStatus();

    // ████████████████████████████████████████████████████████████████████████
    // 3. OBSERVER – Attach alert system to subjects
    // ████████████████████████████████████████████████████████████████████████
    printSectionHeader("3. Observer Pattern");

    auto alertSystem = std::make_shared<Observer::AlertSystem>("Main Security Panel");

    hallSensor->attach(alertSystem);
    frontCamera->attach(alertSystem);
    frontLock->attach(alertSystem);

    Observer::EventManager eventBus;
    eventBus.subscribe("motion",    alertSystem);
    eventBus.subscribe("door_lock", alertSystem);

    std::cout << "Alert system attached to hallway sensor, front camera, front lock.\n";

    // ████████████████████████████████████████████████████████████████████████
    // 4. COMMAND – Turn on living room, set temperature, undo
    // ████████████████████████████████████████████████████████████████████████
    printSectionHeader("4. Command Pattern");

    Command::CommandInvoker invoker;

    // Turn on living room light
    invoker.executeCommand(
        std::make_unique<Command::TurnOnCommand>(livingLight));

    // Set temperature
    invoker.executeCommand(
        std::make_unique<Command::SetTemperatureCommand>(livingTherm, 24.0));

    std::cout << "\nLiving room light is: "
              << (livingLight->isEnabled() ? "ON" : "OFF") << "\n";
    std::cout << "Thermostat target: "
              << livingTherm->getTargetTemperature() << " °C\n";

    // Undo last command (temperature revert)
    invoker.undoLastCommand();
    std::cout << "After undo – Thermostat target: "
              << livingTherm->getTargetTemperature() << " °C\n";

    // Macro batch – turn on entire first floor
    invoker.addToQueue(std::make_unique<Command::TurnOnCommand>(bedLight));
    invoker.addToQueue(std::make_unique<Command::TurnOnCommand>(bedTherm));
    invoker.executeQueue();

    // ████████████████████████████████████████████████████████████████████████
    // 5. STATE – Light state transitions
    // ████████████████████████████████████████████████████████████████████████
    printSectionHeader("5. State Pattern");

    std::cout << "Bedroom light state: "
              << livingLight->getCurrentState()->getStateName() << "\n";

    livingLight->turnOn();
    std::cout << "After turnOn() – state: "
              << livingLight->getCurrentState()->getStateName() << "\n";

    livingLight->changeState(std::make_unique<State::StandbyState>());
    std::cout << "After changeState(Standby) – state: "
              << livingLight->getCurrentState()->getStateName() << "\n";

    livingLight->changeState(std::make_unique<State::InactiveState>());
    std::cout << "After changeState(Inactive) – state: "
              << livingLight->getCurrentState()->getStateName() << "\n";

    // ████████████████████████████████████████████████████████████████████████
    // 6. STRATEGY – Automation modes
    // ████████████████████████████████████████████████████████████████████████
    printSectionHeader("6. Strategy Pattern");

    hub->setAutomationStrategy(
        std::make_unique<Strategy::SecurityStrategy>());
    hub->executeAutomation();

    hub->setAutomationStrategy(
        std::make_unique<Strategy::ComfortStrategy>());
    hub->executeAutomation();

    hub->setAutomationStrategy(
        std::make_unique<Strategy::EnergyEfficiencyStrategy>());
    hub->executeAutomation();

    // ████████████████████████████████████████████████████████████████████████
    // 7. OBSERVER – Trigger events after sensors are active
    // ████████████████████████████████████████████████████████████████████████
    printSectionHeader("3b. Observer – Trigger Events");

    hub->turnOn(); // ensure all devices are online
    hallSensor->triggerMotion();
    frontCamera->detectMotion();
    frontLock->unlock("9999"); // wrong pin → alarm

    alertSystem->printAlertHistory();

    // ████████████████████████████████████████████████████████████████████████
    // 8. ADAPTER – Integrate a legacy device
    // ████████████████████████████████████████████████████████████████████████
    printSectionHeader("7. Adapter Pattern");

    auto legacyHVAC = std::make_shared<Adapter::LegacyDevice>("OldHVAC-5000");
    Adapter::LegacyDeviceAdapter adapter(legacyHVAC);

    adapter.powerOn();
    adapter.setParameter("channel_0", "22");   // set temperature channel
    adapter.setParameter("channel_1", "60");   // fan speed channel

    std::cout << "Protocol : " << adapter.getProtocolVersion() << "\n";
    std::cout << "Status   : " << adapter.queryStatus()        << "\n";

    adapter.powerOff();

    // ── Summary ─────────────────────────────────────────────────────────────
    totalTimer.stop();
    printSectionHeader("Demo Complete");
    std::cout << "Total demo time: " << totalTimer.formatElapsed() << "\n";
    std::cout << "Smart Home System shut down gracefully.\n\n";

    return 0;
}
