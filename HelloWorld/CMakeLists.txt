cmake_minimum_required(VERSION 3.18)
project(hello_world)

set(CMAKE_VERBOSE_MAKEFILE ON)

enable_testing()

set(HELLO_WORLD_DIR_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(hello)
add_subdirectory(world)

add_executable(main ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_include_directories(main PUBLIC world)

target_link_libraries(main PUBLIC hellolib)
target_link_libraries(main PUBLIC worldlib)

add_subdirectory(tests)