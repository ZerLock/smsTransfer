#pragma once

#include "IService.hpp"
#include <boost/asio.hpp>
#include <iostream>
#include <string>

class SmsRedirectionService : public IService {
    public:
        SmsRedirectionService();
        ~SmsRedirectionService();

        bool init() override;

        void run() override;

        void kill() override;

    protected:
    private:
        std::string m_pinCode;
        boost::asio::io_service m_ioService;
        boost::asio::serial_port m_port;

        std::string sendCommand(const std::string& command);

        bool verifyResponse(const std::string& response, const std::string& validator);
};
