cmake_minimum_required(VERSION 3.10)

project(game C)

option(game_vendored "Use vendored libraries" OFF)

if(game_vendored)
    add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)
else()
    find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
endif()

file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/include/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/*.c"
        )


find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

add_executable(game WIN32 ${all_SRCS})

target_link_libraries(game PRIVATE SDL3::SDL3 OpenGL::GL GLEW::GLEW)

target_include_directories(game PRIVATE "${PROJECT_SOURCE_DIR}/include")

