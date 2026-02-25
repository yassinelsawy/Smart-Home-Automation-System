#include "../../include/factory/PremiumDeviceFactory.h"

namespace SmartHome {
namespace Factory {

std::unique_ptr<Devices::Light>
PremiumDeviceFactory::createLight(const std::string& name,
                                   const std::string& id,
                                   const std::string& location) {
    auto light = std::make_unique<Devices::Light>(name, id, location);
    light->setBrightness(100);
    light->setColor("#FFD700");  // Full-spectrum warm-white
    return light;
}

std::unique_ptr<Devices::Thermostat>
PremiumDeviceFactory::createThermostat(const std::string& name,
                                        const std::string& id,
                                        const std::string& location) {
    auto t = std::make_unique<Devices::Thermostat>(name, id, location);
    t->setTargetTemperature(22.0);  // Tighter comfort band
    return t;
}

std::unique_ptr<Devices::Camera>
PremiumDeviceFactory::createCamera(const std::string& name,
                                    const std::string& id,
                                    const std::string& location) {
    // Premium cameras start in recording-ready state
    return std::make_unique<Devices::Camera>(name, id, location);
}

std::unique_ptr<Devices::MotionSensor>
PremiumDeviceFactory::createMotionSensor(const std::string& name,
                                          const std::string& id,
                                          const std::string& location) {
    auto sensor = std::make_unique<Devices::MotionSensor>(name, id, location);
    sensor->setSensitivity(9);  // Higher sensitivity
    return sensor;
}

std::unique_ptr<Devices::DoorLock>
PremiumDeviceFactory::createDoorLock(const std::string& name,
                                      const std::string& id,
                                      const std::string& location) {
    return std::make_unique<Devices::DoorLock>(name, id, location);
}

std::string PremiumDeviceFactory::getFactoryName() const {
    return "PremiumDeviceFactory";
}

} // namespace Factory
} // namespace SmartHome
