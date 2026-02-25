#include "../../include/core/RoomGroup.h"
#include <iostream>

namespace SmartHome {
namespace Core {

RoomGroup::RoomGroup(const std::string& roomName,
                     const std::string& roomType,
                     int                floorNumber)
    : DeviceGroup(roomName)
    , m_roomType(roomType)
    , m_floorNumber(floorNumber)
{}

void RoomGroup::getStatus() const {
    std::cout << "Room [" << m_name << "]"
              << " | Type: "  << m_roomType
              << " | Floor: " << m_floorNumber
              << " | Devices: " << childCount() << "\n";
    for (std::size_t i = 0; i < childCount(); ++i) {
        std::cout << "  ";
        getChild(i)->getStatus();
    }
}

const std::string& RoomGroup::getRoomType()    const { return m_roomType;    }
int                RoomGroup::getFloorNumber() const { return m_floorNumber; }

} // namespace Core
} // namespace SmartHome
