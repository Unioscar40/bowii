cmake_minimum_required(VERSION 3.10)

project(bowii)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

message(STATUS "compiler: " ${CMAKE_CXX_COMPILER_ID})

set(BOWII_MAJOR_VERSION 1)
set(BOWII_MINOR_VERSION 0)
set(BOWII_PATCH_VERSION 0)
set(BOWII_VERSION
    ${BOWII_MAJOR_VERSION}.${BOWII_MINOR_VERSION}.${BOWII_PATCH_VERSION})
set(BOWII_VERSION_STRING "${BOWII_VERSION}")

aux_source_directory(lib/src LIB_SRC)

add_executable(${PROJECT_NAME} main.cpp ${LIB_SRC})

add_library(vectorii 
    lib/inc/bowii/vectorii.h
    lib/src/vectorii.cpp
)

target_link_libraries(bowii PUBLIC vectorii)

add_subdirectory(vectorii)

target_include_directories(bowii PUBLIC 
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/vectorii")                       

add_executable(${PROJECT_NAME} main.cpp ${LIB_SRC})