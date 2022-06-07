cmake_minimum_required(VERSION 3.6)
project(TangaraTest CXX)

set(CMAKE_CXX_STANDARD 17)
set(SOURCES main.cpp EnigmaLabs.Gen.cpp MyClass.cpp MyClass.hpp)

execute_process(
        COMMAND python TangaraGen.py tgrefldata.json
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(TangaraTest ${SOURCES})

target_link_libraries(TangaraTest PRIVATE Tangara.Runtime.Cpp)