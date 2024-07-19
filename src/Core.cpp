#include "Core.hpp"

Core::Core()
    : m_services()
    , m_threads() {}

Core::~Core() {
    for (auto& thread : m_threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
}

bool Core::addService(const std::shared_ptr<IService>& service) {
    m_services.push_back(service);
    return true;
}

void Core::run() {
    // Init
    for (int i = 0; i < m_services.size(); i++) {
        bool initialized = m_services.at(i)->init();
        if (!initialized) {
            m_services.erase(m_services.begin() + i);
        }
    }

    // Run
    for (auto& service : m_services) {
        m_threads.emplace_back([service]() {
            service->run();
        });
    }

    // Kill
    for (auto& service : m_services) {
        service->kill();
    }
}
