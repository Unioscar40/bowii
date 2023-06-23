cmake_minimum_required(VERSION 3.10)

project(bowii-test)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

message(STATUS "compiler: " ${CMAKE_CXX_COMPILER_ID})

set(BOWII_MAJOR_VERSION 1)
set(BOWII_MINOR_VERSION 0)
set(BOWII_PATCH_VERSION 0)
set(BOWII_VERSION
    ${BOWII_MAJOR_VERSION}.${BOWII_MINOR_VERSION}.${BOWII_PATCH_VERSION})
set(BOWII_VERSION_STRING "${BOWII_VERSION}")

add_subdirectory(lib/bowii)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(bowii-test PUBLIC bowii)

target_include_directories(bowii PUBLIC "${PROJECT_SOURCE_DIR}/lib/bowii")