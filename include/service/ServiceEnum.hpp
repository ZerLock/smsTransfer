#pragma once

#include <boost/assign/list_of.hpp>
#include <map>

enum ServiceEnum {
    SMS_REDIRECTION,
};

static std::map<std::string, ServiceEnum> serviceEnumMap = boost::assign::map_list_of("SMS_REDIRECTION", ServiceEnum::SMS_REDIRECTION);
