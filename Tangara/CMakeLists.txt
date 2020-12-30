cmake_minimum_required(VERSION 3.10)

project(Tangara)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_library(Tangara ${SOURCES})

target_include_directories(Tangara 
	PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)