cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME app)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} main.cpp)

# Правильная линковка с библиотекой mylib
target_link_libraries(${PROJECT_NAME} PRIVATE mylib)

# Подключение заголовочных файлов
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/mylib/inc)