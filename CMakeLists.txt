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
    src/core/SmartHomeHub.cpp

    # ── devices ───────────────────────────────────────────────────────────────
    src/devices/Light.cpp
    src/devices/Thermostat.cpp
    src/devices/Camera.cpp
    src/devices/MotionSensor.cpp
    src/devices/DoorLock.cpp

    # ── command ───────────────────────────────────────────────────────────────
    src/command/TurnOnCommand.cpp
    src/command/TurnOffCommand.cpp
    src/command/SetTemperatureCommand.cpp
    src/command/CommandInvoker.cpp

    # ── state ─────────────────────────────────────────────────────────────────
    src/state/ActiveState.cpp
    src/state/InactiveState.cpp
    src/state/StandbyState.cpp

    # ── observer ──────────────────────────────────────────────────────────────
    src/observer/EventManager.cpp
    src/observer/AlertSystem.cpp

    # ── strategy ──────────────────────────────────────────────────────────────
    src/strategy/EnergyEfficiencyStrategy.cpp
    src/strategy/SecurityStrategy.cpp
    src/strategy/ComfortStrategy.cpp

    # ── factory ───────────────────────────────────────────────────────────────
    src/factory/BasicDeviceFactory.cpp
    src/factory/PremiumDeviceFactory.cpp

    # ── adapter ───────────────────────────────────────────────────────────────
    src/adapter/LegacyDevice.cpp
    src/adapter/LegacyDeviceAdapter.cpp

    # ── utils ─────────────────────────────────────────────────────────────────
    src/utils/Logger.cpp
    src/utils/Timer.cpp
)

add_library(smarthome_core STATIC ${CORE_SOURCES})

target_include_directories(smarthome_core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
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
# Unit tests (CTest integration)
# ═════════════════════════════════════════════════════════════════════════════

enable_testing()

function(add_smarthome_test test_name source_file)
    add_executable(${test_name} ${source_file})
    target_link_libraries(${test_name} PRIVATE smarthome_core)
    add_test(
        NAME    ${test_name}
        COMMAND ${test_name}
    )
endfunction()

add_smarthome_test(test_composite tests/test_composite.cpp)
add_smarthome_test(test_command   tests/test_command.cpp)
add_smarthome_test(test_observer  tests/test_observer.cpp)

# ═════════════════════════════════════════════════════════════════════════════
# Install rules (optional – for packaging)
# ═════════════════════════════════════════════════════════════════════════════

install(TARGETS SmartHome
    RUNTIME DESTINATION bin
)
install(DIRECTORY include/
    DESTINATION include
)
