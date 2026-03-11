cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME myLib)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 20)

# Создаем библиотеку
add_library("${PROJECT_NAME}" STATIC 
    myLib/src/Book.cpp
    myLib/src/lib.cpp
)

# Указываем где искать заголовочные файлы для библиотеки
target_include_directories("${PROJECT_NAME}" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/myLib/inc)

# Создаем исполняемый файл
add_executable(2LB3 2LB3.cpp)

# Линкуем библиотеку
target_link_libraries(2LB3 PRIVATE "${PROJECT_NAME}")

# Указываем где искать заголовочные файлы для исполняемого файла
target_include_directories(2LB3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/myLib/inc)