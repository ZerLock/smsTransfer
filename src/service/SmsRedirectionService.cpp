#include "SmsRedirectionService.hpp"

SmsRedirectionService::SmsRedirectionService()
    : m_pinCode()
    , m_ioService()
    , m_port(m_ioService) {}

SmsRedirectionService::~SmsRedirectionService() {
    kill();
}

bool SmsRedirectionService::init() {
    std::cout << "SMS REDIRECTION" << std::endl
              << "---------------" << std::endl;

    // Get PIN code
    std::cout << "Please write your PIN code : ";
    std::getline(std::cin, m_pinCode);

    // Start serial communication
    std::cout << "Setting up communication..." << std::endl;

    try {
        m_port.open("/dev/ttyUSB0");
        m_port.set_option(boost::asio::serial_port_base::baud_rate(115200));
    } catch (std::exception& e) {
        std::cerr << "Error opening serial port: " << e.what() << std::endl;
        return false;
    }

    // Unlock SIM with PIN code
    sendCommand("AT+CPIN=" + m_pinCode);
    std::string unlockPinResponse = sendCommand("AT+CPIN?");
    if (!verifyResponse(unlockPinResponse, "READY")) {
        std::cerr << "Unable to unlock SIM card with given PIN code" << std::endl;
        return false;
    }

    // Setting up SMS mode
    sendCommand("AT+CMGF=1");

    return true;
}

void SmsRedirectionService::run() {
    while (true) {
        // Get unread SMS
        std::string response = sendCommand("AT+CMGL=\"REC UNREAD\"");
        if (!verifyResponse(response, "+CMGL")) {
            std::this_thread::sleep_for(std::chrono::seconds(5));
            continue;
        }

        // Process the SMS
        std::cout << "New SMS received : " << std::endl;
        std::cout << response << std::endl;

        // Send SMS by email
    }
}

void SmsRedirectionService::kill() {
    if (m_port.is_open()) {
        m_port.close();
    }
    m_ioService.stop();
}

std::string SmsRedirectionService::sendCommand(const std::string& command) {
    write(m_port, boost::asio::buffer(command + "\r"));

    std::string response;
    char c;
    while (true) {
        boost::system::error_code ec;
        size_t n = read(m_port, boost::asio::buffer(&c, 1), ec);
        if (ec || n == 0) {
            break;
        }
        response += c;
        if (response.size() > 2 && response.substr(response.size() - 2) == "\r\n") {
            break;
        }
    }
    return response;
}

bool SmsRedirectionService::verifyResponse(const std::string& response, const std::string& validator) {
    return response.find(validator) != std::string::npos;
}
