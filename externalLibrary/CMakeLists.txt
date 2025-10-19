cmake_minimum_required(VERSION 3.16)

project(ExternalProjectProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# interface

add_library(extLibInterface INTERFACE)

target_include_directories(extLibInterface
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# implementation

add_library(extLibrary
    implementation.cpp
)

target_link_libraries(extLibrary
    PUBLIC extLibInterface
)
