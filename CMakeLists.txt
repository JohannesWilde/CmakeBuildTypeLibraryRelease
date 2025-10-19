cmake_minimum_required(VERSION 3.16)

project(TestingCmakeExternalProjects LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# https://stackoverflow.com/questions/60636141/different-cmake-build-type-per-target/60653620#60653620
include(ExternalProject)
ExternalProject_Add(extLibTarget
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/externalLibrary
    CMAKE_ARGS
        # -DBUILD_LIST=core,imgproc
        # -DBUILD_SHARED_LIBS=OFF
        -DCMAKE_BUILD_TYPE=Release
        # -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/deps/opencv
        INSTALL_COMMAND "" # do not install the extLibrary by itself
)

find_package(extLibrary
    PATHS ${CMAKE_CURRENT_BINARY_DIR}/externalLibrary
    NO_DEFAULT_PATH
)

# Abort if we weren't able to find it.
if(NOT ExternalProjectLibrary_FOUND)
    message(WARNING "extLibrary was not found.")
    return()
endif()


# executable

add_executable(testExecutable
    main.cpp
)

target_link_libraries(testExecutable
    PRIVATE ${ExternalProjectLibrary_LIB}
)

message(WARNING "ExternalProjectLibrary_LIB: ${ExternalProjectLibrary_LIB}")
