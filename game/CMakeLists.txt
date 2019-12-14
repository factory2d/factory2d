cmake_minimum_required(VERSION 2.8.9)
project (bin/game)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMakeModules" ${CMAKE_MODULE_PATH})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++17 -fpermissive -lSDL2 -lSDL2_image -lGLEW -lGLU -lGL")

file(GLOB SRC_CORE		"../core/*"
                      "../core/Asset/*"
                      "../core/Behaviour/*"
                      "../core/Input/*"
                      "../core/Material/*"
                      "../core/Objects/*"
                      "../core/Render/*"
                      "../core/Scene/*"
                      "../core/TagManager/*"
                      "../core/Timer/*"
                      "../core/Window/*"
)

file(GLOB SRC_GAME		"*")

add_executable(bin/game ${SRC_GAME} ${SRC_CORE})
target_link_libraries(bin/game)
