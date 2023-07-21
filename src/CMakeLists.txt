set(TARGET_NAME bowii)
project(${TARGET_NAME} LANGUAGES C CXX VERSION 1.0)

add_compile_options("-msse4.2")

add_library(${TARGET_NAME} STATIC)

target_sources(${TARGET_NAME} 
    PRIVATE
        utils.cpp
        MathVector.cpp
)

target_include_directories(${TARGET_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../include/private
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include/public>
)