#include "../../include/observer/EventManager.h"
#include "../../include/utils/Logger.h"
#include <algorithm>

namespace SmartHome {
namespace Observer {

void EventManager::subscribe(const std::string&             eventType,
                              std::shared_ptr<IObserver>     observer) {
    m_listeners[eventType].push_back(observer);
    Utils::Logger::instance().debug(
        "Observer subscribed to event: " + eventType, "EventManager");
}

void EventManager::unsubscribe(const std::string&         eventType,
                                std::shared_ptr<IObserver> observer) {
    auto it = m_listeners.find(eventType);
    if (it != m_listeners.end()) {
        auto& vec = it->second;
        vec.erase(std::remove(vec.begin(), vec.end(), observer), vec.end());
    }
}

void EventManager::publish(const std::string& eventType,
                            const std::string& source,
                            const std::string& detail) {
    Utils::Logger::instance().info(
        "Event [" + eventType + "] from [" + source + "]: " + detail,
        "EventManager");

    auto it = m_listeners.find(eventType);
    if (it != m_listeners.end()) {
        for (auto& obs : it->second) {
            obs->onEvent(source, detail);
        }
    }
}

} // namespace Observer
} // namespace SmartHome
