#include "Core.hpp"
#include "ServiceEnum.hpp"
#include "ServiceFactory.hpp"
#include "SmsRedirectionService.hpp"
#include <iostream>

void printUsage(char** av, const std::string& badOption = "-") {
    std::cerr << av[0] << ": Illegal options -- " << badOption << std::endl
              << std::endl
              << "You must provide at least 1 service as command options" << std::endl
              << std::endl
              << "Usage:" << std::endl
              << "  " << av[0] << " [SMS_REDIRECTION]" << std::endl;
}

int main(int ac, char** av) {
    if (ac <= 1) {
        printUsage(av);
        return EXIT_FAILURE;
    }

    Core core;

    std::vector<std::string> arguments(av + 1, av + ac);
    ServiceFactory serviceFactory;
    for (auto& arg : arguments) {
        try {
            ServiceEnum type = serviceEnumMap.at(arg);
            std::shared_ptr<IService> service = serviceFactory.createService(type);
            core.addService(service);
        } catch (std::exception e) {
            printUsage(av, arg);
            return EXIT_FAILURE;
        }
    }

    core.run();

    return EXIT_SUCCESS;
}
