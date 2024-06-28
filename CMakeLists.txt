cmake_minimum_required(VERSION 3.10)
project(MultithreadedWebServer)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(multithreaded_web_server src/main.cpp src/Multithread_Summer_Project.cpp)
