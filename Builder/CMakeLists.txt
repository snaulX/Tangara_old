cmake_minimum_required(VERSION 3.6)
project(Tangara.Builder)

set(CMAKE_CXX_STANDARD 17)
set(TANGARA_BUILDER_DLL OFF CACHE BOOL "Builds shared library")

set(SOURCES Source/EntryBuilder.cpp Source/EntryRule.cpp Source/ClassBuilder.cpp Source/Utils.cpp Source/TgValue.cpp
        Source/StructBuilder.cpp Source/EnumBuilder.cpp)

if (TANGARA_DLL)
    add_library(Tangara.Builder SHARED ${SOURCES})
else()
    add_library(Tangara.Builder STATIC ${SOURCES})
endif()

target_include_directories(Tangara.Builder PUBLIC Include/)
target_link_libraries(Tangara.Builder PUBLIC Tangara)
