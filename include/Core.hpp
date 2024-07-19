#pragma once

#include "IService.hpp"
#include <memory>
#include <thread>

class Core {
    public:
        Core();
        ~Core();

        bool addService(const std::shared_ptr<IService>& service);

        void run();

    protected:
    private:
        std::vector<std::shared_ptr<IService>> m_services;
        std::vector<std::thread> m_threads;
};
