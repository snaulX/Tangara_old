cmake_minimum_required(VERSION 3.6)
project(Tangara)

set(CMAKE_C_STANDARD 99)
set(TANGARA_DLL OFF CACHE BOOL "Builds shared library")
set(TANGARA_BUILDER ON CACHE BOOL "Builds Tangara.Builder project")
set(TANGARA_STD ON CACHE BOOL "Builds Tangara.Std project")
set(TANGARA_TEST ON CACHE BOOL "Builds test")

set(SOURCES Source/tg_funcs.c)

if (TANGARA_DLL)
    add_library(Tangara SHARED ${SOURCES})
else()
    add_library(Tangara STATIC ${SOURCES})
endif()

target_include_directories(Tangara PUBLIC Include/)

if (TANGARA_STD)
    add_subdirectory(StdLib)
endif()

if (TANGARA_BUILDER)
    add_subdirectory(Builder)
endif()

if (TANGARA_TEST)
	add_subdirectory(Test)
endif()
