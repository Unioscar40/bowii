cmake_minimum_required(VERSION 3.15)

set(TARGET_NAME bowiiTests)
project(${TARGET_NAME} LANGUAGES C CXX VERSION 1.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(src)
add_subdirectory(test)




