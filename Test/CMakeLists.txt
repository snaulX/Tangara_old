cmake_minimum_required(VERSION 3.6)
project(TangaraTest)

add_executable(TangaraTest main.cpp)

target_link_libraries(TangaraTest PUBLIC
        Tangara
        Tangara.Builder)