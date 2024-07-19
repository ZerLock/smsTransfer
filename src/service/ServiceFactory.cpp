#include "ServiceFactory.hpp"

ServiceFactory::ServiceFactory()
    : m_factories() {
    m_factories[ServiceEnum::SMS_REDIRECTION] = &ServiceFactory::create<SmsRedirectionService>;
}

ServiceFactory::~ServiceFactory() = default;

std::shared_ptr<IService> ServiceFactory::createService(const ServiceEnum& service) {
    auto iterator = m_factories.find(service);
    if (iterator == m_factories.end()) {
        throw new std::invalid_argument("Service not found");
    }
    return iterator->second();
}
