cmake_minimum_required(VERSION 3.16)
project(clove)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
set(SOURCES main.cpp)

find_package(SDL2 REQUIRED)

add_executable(clove_debug ${SOURCES})
set_target_properties(clove_debug PROPERTIES 
    OUTPUT_NAME "clove_debug"
    COMPILE_FLAGS "${CMAKE_CXX_FLAGS_DEBUG}")
target_link_libraries(clove_debug SDL2)
    
add_executable(clove_release ${SOURCES})
set_target_properties(clove_release PROPERTIES 
    OUTPUT_NAME "clove"
    COMPILE_FLAGS "${CMAKE_CXX_FLAGS_RELEASE}")
target_link_libraries(clove_release SDL2)