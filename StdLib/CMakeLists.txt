cmake_minimum_required(VERSION 3.6)
project(Tangara.Std)

set(CMAKE_CXX_STANDARD 17)
set(TANGARA_STD_DLL OFF CACHE BOOL "Builds shared library")

set(SOURCES Source/tgstdlib.cpp)

if (TANGARA_STD_DLL)
    add_library(Tangara.Std SHARED ${SOURCES})
else()
    add_library(Tangara.Std STATIC ${SOURCES})
endif()

target_include_directories(Tangara.Std PUBLIC Include/)
target_link_libraries(Tangara.Std PUBLIC Tangara)
target_link_libraries(Tangara.Std PRIVATE Tangara.Builder)
