cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(TgBuild C)

set(CMAKE_C_STANDARD 11)

set(SOURCES main.c)

add_executable(TgBuild main.c lua_tgbuild.c tgbuild_util.c)

# !Warning: you must reload cmake every time you change TestProj
file(COPY TestProj DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
file(COPY Modules DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

# add dependencies
include(cmake/CPM.cmake)

CPMAddPackage(
        NAME lua
        GIT_REPOSITORY https://github.com/lua/lua.git
        VERSION 5.4.4
        DOWNLOAD_ONLY YES
)

if (lua_ADDED)
    # lua has no CMake support, so we create our own target

    file(GLOB lua_sources ${lua_SOURCE_DIR}/*.c)
    list(REMOVE_ITEM lua_sources "${lua_SOURCE_DIR}/lua.c" "${lua_SOURCE_DIR}/luac.c" "${lua_SOURCE_DIR}/onelua.c")
    add_library(lua STATIC ${lua_sources})

    target_include_directories(lua
            PUBLIC
            $<BUILD_INTERFACE:${lua_SOURCE_DIR}>
            )
endif()

target_link_libraries(TgBuild lua)