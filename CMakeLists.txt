cmake_minimum_required(VERSION 3.15)

set(TARGET_NAME bowii)
project(${TARGET_NAME} LANGUAGES C CXX VERSION 1.0)

add_compile_options("-msse4.2")

add_library(${TARGET_NAME} STATIC)

target_sources(${TARGET_NAME} 
    PRIVATE
        src/utils.cpp
        src/vectorii.cpp
)

target_include_directories(${TARGET_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/private
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/public>
)




# file(GLOB_RECURSE TARGET_SOURCES
#     "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
#     "${CMAKE_CURRENT_SOURCE_DIR}/src/**/*.cpp"
#     )

# file(GLOB_RECURSE TARGET_PUBLIC_HEADERS
#     "${CMAKE_CURRENT_SOURCE_DIR}/include/public/**/*.hpp"
# )

# file(GLOB_RECURSE TARGET_PRIVATE_HEADERS
#     "${CMAKE_CURRENT_SOURCE_DIR}/include/private/**/*.hpp"
# )

# target_include_directories(${TARGET_NAME}
#     PUBLIC
#         "${CMAKE_CURRENT_SOURCE_DIR}/include/public"
#     PRIVATE
#         "${CMAKE_CURRENT_SOURCE_DIR}/include/private"
# )

# target_sources(${TARGET_NAME}
#     PUBLIC
#         ${TARGET_PUBLIC_HEADERS}
#     PRIVATE
#         ${TARGET_PRIVATE_HEADERS}
#         ${TARGET_SOURCES}
# )


