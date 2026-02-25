#include "../../include/core/FloorGroup.h"
#include <iostream>

namespace SmartHome {
namespace Core {

FloorGroup::FloorGroup(const std::string& name, int floorNumber)
    : DeviceGroup(name)
    , m_floorNumber(floorNumber)
{}

void FloorGroup::getStatus() const {
    std::cout << "Floor [" << m_name << "]"
              << " | Floor #" << m_floorNumber
              << " | Rooms: "  << childCount() << "\n";
    for (std::size_t i = 0; i < childCount(); ++i) {
        getChild(i)->getStatus();
    }
}

int FloorGroup::getFloorNumber() const { return m_floorNumber; }

} // namespace Core
} // namespace SmartHome
