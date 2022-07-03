cmake_minimum_required(VERSION 3.6)
project(Tangara)

set(CMAKE_CXX_STANDARD 17)
set(TANGARA_DLL OFF CACHE BOOL "Builds shared library")
set(TANGARA_CPP ON CACHE BOOL "Builds Tangara.Runtime.Cpp module")
set(TANGARA_TEST ON CACHE BOOL "Builds test")

set(SOURCES Source/TgObj.cpp Source/Class.cpp Source/Constructor.cpp Source/Entry.cpp Source/Method.cpp Source/Utils.cpp
        Source/TgStd.cpp Source/Type.cpp)

if (TANGARA_DLL)
    add_library(Tangara SHARED ${SOURCES})
else()
    add_library(Tangara STATIC ${SOURCES})
endif()

target_include_directories(Tangara PUBLIC Include/)

if (TANGARA_CPP)
    add_subdirectory(Runtime/Cpp)
    if (TANGARA_TEST)
        add_subdirectory(TestCpp)
    endif()
endif()
