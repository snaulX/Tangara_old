cmake_minimum_required(VERSION 3.6)
project(Tangara CXX)

set(CMAKE_CXX_STANDARD 17)
set(TANGARA_DLL OFF CACHE BOOL "Builds shared library")

set(SOURCES Source/Class.cpp Source/Entry.cpp Source/Function.cpp)

if (TANGARA_DLL)
    add_library(Tangara SHARED ${SOURCES})
else()
    add_library(Tangara STATIC ${SOURCES})
endif()

target_include_directories(Tangara PUBLIC Include/)

