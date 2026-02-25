/**
 * @file test_command.cpp
 * @brief Unit tests for Command Pattern (CommandInvoker, TurnOn/Off, SetTemp).
 */

#include "../include/command/CommandInvoker.h"
#include "../include/command/TurnOnCommand.h"
#include "../include/command/TurnOffCommand.h"
#include "../include/command/SetTemperatureCommand.h"
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

void testTurnOnExecuteAndUndo() {
    auto light   = std::make_shared<Devices::Light>("L", "L1", "Hall");
    auto invoker = Command::CommandInvoker{};

    invoker.executeCommand(
        std::make_unique<Command::TurnOnCommand>(light));
    TEST("Light ON after TurnOnCommand::execute", light->isEnabled());

    invoker.undoLastCommand();
    TEST("Light OFF after TurnOnCommand::undo", !light->isEnabled());
}

void testTurnOffExecuteAndUndo() {
    auto light   = std::make_shared<Devices::Light>("L", "L2", "Hall");
    auto invoker = Command::CommandInvoker{};

    light->turnOn(); // pre-condition
    invoker.executeCommand(
        std::make_unique<Command::TurnOffCommand>(light));
    TEST("Light OFF after TurnOffCommand::execute", !light->isEnabled());

    invoker.undoLastCommand();
    TEST("Light ON after TurnOffCommand::undo", light->isEnabled());
}

void testSetTemperatureAndUndo() {
    auto therm   = std::make_shared<Devices::Thermostat>("T", "T1", "Living");
    auto invoker = Command::CommandInvoker{};

    therm->setTargetTemperature(20.0);
    invoker.executeCommand(
        std::make_unique<Command::SetTemperatureCommand>(therm, 25.0));
    TEST("Thermostat at 25 after SetTemperature", therm->getTargetTemperature() == 25.0);

    invoker.undoLastCommand();
    TEST("Thermostat back to 20 after undo", therm->getTargetTemperature() == 20.0);
}

void testMacroBatch() {
    auto light1 = std::make_shared<Devices::Light>("L1", "L10", "Kitchen");
    auto light2 = std::make_shared<Devices::Light>("L2", "L11", "Kitchen");
    auto invoker = Command::CommandInvoker{};

    invoker.addToQueue(std::make_unique<Command::TurnOnCommand>(light1));
    invoker.addToQueue(std::make_unique<Command::TurnOnCommand>(light2));
    invoker.executeQueue();

    TEST("Light1 ON after batch", light1->isEnabled());
    TEST("Light2 ON after batch", light2->isEnabled());
    TEST("History size == 2", invoker.historySize() == 2);
}

int main() {
    std::cout << "=== Command Pattern Tests ===\n";
    testTurnOnExecuteAndUndo();
    testTurnOffExecuteAndUndo();
    testSetTemperatureAndUndo();
    testMacroBatch();
    std::cout << "\nResults: " << g_passed << " passed, " << g_failed << " failed.\n";
    return g_failed == 0 ? 0 : 1;
}
