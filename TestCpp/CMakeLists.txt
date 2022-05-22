cmake_minimum_required(VERSION 3.6)
project(TangaraTest CXX)

set(CMAKE_CXX_STANDARD 17)
set(SOURCES main.cpp)

add_executable(TangaraTest ${SOURCES})

target_link_libraries(TangaraTest PRIVATE Tangara.Runtime.Cpp)