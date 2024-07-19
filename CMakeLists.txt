cmake_minimum_required(VERSION 3.27)
set(CMAKE_CXX_STANDARD 20)
set(Boost_USE_STATIC_LIB ON)

project(smsTransfer)

find_package(Boost REQUIRED COMPONENTS system)

set(INCLUDES
    "include"
    "include/service"
)

set(SOURCES
    src/main.cpp
    src/Core.cpp
    src/service/ServiceFactory.cpp
    src/service/SmsRedirectionService.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDES})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
target_link_libraries(${PROJECT_NAME} PUBLIC Boost::system pthread)
