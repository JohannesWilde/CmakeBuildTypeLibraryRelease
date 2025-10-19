# Overview

This repo demonstrates how to build a component [library] of a project always as `Release`, regardless of the `CMAKE_BUILD_TYPE` selected for the top project.

It explicitely does not use `ExternalProject_Add` and `find_package` - which would require one to `install` the library, introduce a lot of build-time synchronization issues and would hide usefull things like the `extLibInterface` in this repository.
