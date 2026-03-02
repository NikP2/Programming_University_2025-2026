cmake_minimum_required(VERSION 3.15)
set(PROJECT_NAME mylib_shared)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 20)

add_library("${PROJECT_NAME}" SHARED src/functions.cpp)

target_include_directories("${PROJECT_NAME}" PUBLIC inc)

# НИКАКИХ target_link_libraries ЗДЕСЬ!