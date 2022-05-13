cmake_minimum_required(VERSION 3.6)
project(Tangara.Runtime.Cpp CXX)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES Source/CreateInterface.cpp Source/CreateInterface.hpp Source/TangaraPool.cpp Source/TangaraPool.hpp Source/CreateClass.cpp Source/CreateClass.hpp)

add_library(Tangara.Runtime.Cpp STATIC ${SOURCES})

target_include_directories(Tangara.Runtime.Cpp PUBLIC Include/)
target_link_libraries(Tangara.Runtime.Cpp PUBLIC Tangara)
