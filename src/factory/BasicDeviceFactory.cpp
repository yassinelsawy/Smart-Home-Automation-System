#include "../../include/factory/BasicDeviceFactory.h"

namespace SmartHome {
namespace Factory {

std::unique_ptr<Devices::Light>
BasicDeviceFactory::createLight(const std::string& name,
                                 const std::string& id,
                                 const std::string& location) {
    auto light = std::make_unique<Devices::Light>(name, id, location);
    light->setBrightness(60);
    light->setColor("#FFFFFF");
    return light;
}

std::unique_ptr<Devices::Thermostat>
BasicDeviceFactory::createThermostat(const std::string& name,
                                      const std::string& id,
                                      const std::string& location) {
    auto t = std::make_unique<Devices::Thermostat>(name, id, location);
    t->setTargetTemperature(20.0);
    return t;
}

std::unique_ptr<Devices::Camera>
BasicDeviceFactory::createCamera(const std::string& name,
                                  const std::string& id,
                                  const std::string& location) {
    return std::make_unique<Devices::Camera>(name, id, location);
}

std::unique_ptr<Devices::MotionSensor>
BasicDeviceFactory::createMotionSensor(const std::string& name,
                                        const std::string& id,
                                        const std::string& location) {
    auto sensor = std::make_unique<Devices::MotionSensor>(name, id, location);
    sensor->setSensitivity(5);
    return sensor;
}

std::unique_ptr<Devices::DoorLock>
BasicDeviceFactory::createDoorLock(const std::string& name,
                                    const std::string& id,
                                    const std::string& location) {
    return std::make_unique<Devices::DoorLock>(name, id, location);
}

std::string BasicDeviceFactory::getFactoryName() const {
    return "BasicDeviceFactory";
}

} // namespace Factory
} // namespace SmartHome
