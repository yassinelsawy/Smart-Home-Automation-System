cmake_minimum_required(VERSION 3.17)
project(SmartHomeAutomationSystem
    VERSION     1.0.0
    DESCRIPTION "Smart Home Automation System – Design Patterns Demo"
    LANGUAGES   CXX
)

# ── Global C++ standard ──────────────────────────────────────────────────────
set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

# ── Output directories ───────────────────────────────────────────────────────
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# ── Compiler warnings ────────────────────────────────────────────────────────
if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

# ═════════════════════════════════════════════════════════════════════════════
# Core library – shared between main executable and unit tests
# ═════════════════════════════════════════════════════════════════════════════

set(CORE_SOURCES
    # ── core ──────────────────────────────────────────────────────────────────
    src/core/SmartComponent.cpp
    src/core/SmartDevice.cpp
    src/core/DeviceGroup.cpp
    src/core/RoomGroup.cpp
    src/core/FloorGroup.cpp
    src/core/FunctionalGroup.cpp
    src/core/SmartHomeHub.cpp

    # ── devices ───────────────────────────────────────────────────────────────
    src/devices/Light.cpp
    src/devices/Thermostat.cpp
    src/devices/Camera.cpp
    src/devices/MotionSensor.cpp
    src/devices/DoorLock.cpp
    src/devices/BrandALedLight.cpp
    src/devices/BrandAHalogenLight.cpp
    src/devices/BrandBLedLight.cpp
    src/devices/BrandBHalogenLight.cpp
    src/devices/BrandAWiredSCam.cpp
    src/devices/BrandAWirelessSCam.cpp
    src/devices/BrandBWiredSCam.cpp
    src/devices/BrandBWirelessSCam.cpp
    src/devices/BrandASmartThermoA.cpp
    src/devices/BrandASmartThermoB.cpp
    src/devices/BrandBSmartThermoA.cpp
    src/devices/BrandBSmartThermoB.cpp

    # ── command ───────────────────────────────────────────────────────────────
    src/command/ICommand.cpp
    src/command/TurnOnCommand.cpp
    src/command/TurnOffCommand.cpp
    src/command/AutomationEngine.cpp
    src/command/SetTemperatureCommand.cpp

    # ── state ─────────────────────────────────────────────────────────────────
    src/state/OnState.cpp
    src/state/OffState.cpp
    src/state/DimmedState.cpp

    # ── strategy ──────────────────────────────────────────────────────────────
    src/strategy/EnergyEfficiencyStrategy.cpp
    src/strategy/ComfortStrategy.cpp

    # ── factory ───────────────────────────────────────────────────────────────
    src/factory/SmartDeviceFactory.cpp
    src/factory/BrandAFactory.cpp
    src/factory/BrandBFactory.cpp

    # ── adapter ───────────────────────────────────────────────────────────────
    src/adapter/ExternalDevice.cpp
    src/adapter/ExternalDeviceAdapter.cpp
)

add_library(smarthome_core STATIC ${CORE_SOURCES})

target_include_directories(smarthome_core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/core
        ${CMAKE_CURRENT_SOURCE_DIR}/include/devices
        ${CMAKE_CURRENT_SOURCE_DIR}/include/command
        ${CMAKE_CURRENT_SOURCE_DIR}/include/factory
        ${CMAKE_CURRENT_SOURCE_DIR}/include/observer
        ${CMAKE_CURRENT_SOURCE_DIR}/include/state
        ${CMAKE_CURRENT_SOURCE_DIR}/include/strategy
        ${CMAKE_CURRENT_SOURCE_DIR}/include/utils
        ${CMAKE_CURRENT_SOURCE_DIR}/include/adapter
)

# Link pthreads on Linux/macOS for std::mutex
if(UNIX)
    target_link_libraries(smarthome_core PUBLIC pthread)
endif()

# ═════════════════════════════════════════════════════════════════════════════
# Main executable
# ═════════════════════════════════════════════════════════════════════════════

add_executable(SmartHome main.cpp)
target_link_libraries(SmartHome PRIVATE smarthome_core)

# ═════════════════════════════════════════════════════════════════════════════
# Install rules (optional – for packaging)
# ═════════════════════════════════════════════════════════════════════════════

install(TARGETS SmartHome
    RUNTIME DESTINATION bin
)
install(DIRECTORY include/
    DESTINATION include
)
