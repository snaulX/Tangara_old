cmake_minimum_required(VERSION 3.10)

project(Tangara)

set(SOURCES "src/main.cpp" "src/Parser.cpp")

add_library(Tangara ${SOURCES})

target_include_directories(Tangara 
	PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)