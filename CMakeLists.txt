cmake_minimum_required(VERSION 3.16)

project(TestingCmakeExternalProjects LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Always compile externalLibrary as Release.
set(CMAKE_BUILD_TYPE_BACKUP_ ${CMAKE_BUILD_TYPE})
set(CMAKE_BUILD_TYPE Release)

add_subdirectory(externalLibrary)

set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE_BACKUP_})
unset(CMAKE_BUILD_TYPE_BACKUP_)


# executable
add_executable(testExecutable
    main.cpp
)

target_link_libraries(testExecutable
    PRIVATE extLibrary
)
