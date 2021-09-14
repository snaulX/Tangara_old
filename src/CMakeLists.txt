cmake_minimum_required(VERSION 3.6)
project(Tangara C)

set(DYNAMIC false)
set(CMAKE_C_STANDARD 99)
set(SOURCES File.c TangaraCore.c base.c)
set(INCLUDE base.h constants.h File.h TangaraCore.h CodeBlock.h)

include_directories(Tangara ${INCLUDE})

if (DYNAMIC)
    add_library(Tangara SHARED ${SOURCES})
else()
    add_library(Tangara STATIC ${SOURCES})
endif ()

add_subdirectory(test)
