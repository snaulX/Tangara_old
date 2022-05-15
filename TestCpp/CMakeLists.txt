cmake_minimum_required(VERSION 3.6)
project(TangaraTest CXX)

set(CMAKE_CXX_STANDARD 17)
set(SOURCES IMyInterface.cpp IMyInterface.hpp MyClass.cpp MyClass.hpp main.cpp)

# add_executable(TangaraTest ${SOURCES})
add_executable(TangaraTest main.cpp)

# target_link_libraries(TangaraTest PRIVATE Tangara.Runtime.Cpp)