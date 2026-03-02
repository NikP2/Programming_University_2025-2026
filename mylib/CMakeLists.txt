cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME mylib)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 20)

add_library("${PROJECT_NAME}" STATIC src/functions.cpp) #создание статической библиотеки

target_include_directories("${PROJECT_NAME}" PUBLIC inc) # Помещает наш путь в системный путь