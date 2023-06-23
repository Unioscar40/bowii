cmake_minimum_required(VERSION 3.10)

project(bowii-test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(lib/bowii)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(bowii-test PUBLIC bowii)

target_include_directories(bowii PUBLIC 
"${PROJECT_BINARY_DIR}"
"${PROJECT_SOURCE_DIR}/lib/bowii")