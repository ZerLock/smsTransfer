#pragma once

#include "IService.hpp"
#include "ServiceEnum.hpp"
#include "SmsRedirectionService.hpp"
#include <map>

class ServiceFactory {
    public:
        ServiceFactory();
        ~ServiceFactory();

        std::shared_ptr<IService> createService(const ServiceEnum& service);

        template <class T>
        static std::shared_ptr<T> create() {
            return std::make_shared<T>();
        }

    protected:
    private:
        std::map<ServiceEnum, std::function<std::shared_ptr<IService>(void)>> m_factories;
};
