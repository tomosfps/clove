cmake_minimum_required(VERSION 3.16)
project(clove)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
include_directories(include)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
    
add_executable(${PROJECT_NAME} ${SOURCES}
        src/engine.cpp
        include/core/engine.h
        src/textureManager.cpp
        include/graphics/textureManager.h
        include/physics/vector2D.h
        include/physics/transform.h
        include/object/iObject.h
        include/object/gameObject.h
        include/characters/character.h
        src/warrior.cpp
        include/characters/warrior.h
        src/animation.cpp
        include/animation/animation.h
        include/physics/rigidBody.h
        src/eventHandler.cpp
        include/input/eventHandler.h
        src/timer.cpp
        include/timer/timer.h
)
set_target_properties(${PROJECT_NAME} PROPERTIES 
    OUTPUT_NAME ${PROJECT_NAME}
    COMPILE_FLAGS "${CMAKE_CXX_FLAGS_RELEASE}")

target_link_libraries(${PROJECT_NAME} SDL2 SDL2_image)