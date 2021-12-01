cmake_minimum_required(VERSION 3.14)

# Project Infomation
project(
    CPP-Utils
    VERSION 0.1
    LANGUAGES CXX
    DESCRIPTION "Toy CPP utility library"
)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    add_compile_options(-g -O0 -Wall)
elseif(CMAKE_BUILD_TYPE MATCHES Release)
endif()


add_subdirectory(src)

# Unit Tests
enable_testing()
add_subdirectory(tests)