cmake_minimum_required(VERSION 3.6)
project(TangaraTest C)

set(CMAKE_C_STANDARD 99)

add_executable(TangaraTest main.c Person.c Person.h std.c std.h)

target_link_libraries(TangaraTest PUBLIC Tangara)

include_directories(TangaraTest ../)