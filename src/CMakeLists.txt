# Project Information
project(cpp_utils)

add_library(${PROJECT_NAME} SHARED "")

file(
    GLOB_RECURSE
    SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

target_sources(
    ${PROJECT_NAME}
    PRIVATE
    ${SOURCES}
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    ${PROJECT_SOURCE_DIR}/../include
)

message("CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")
if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions(${PROJECT_NAME} PUBLIC _DEBUG)
elseif(CMAKE_BUILD_TYPE MATCHES Release)
endif()