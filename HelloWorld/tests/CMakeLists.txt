cmake_minimum_required(VERSION 3.18)
project(test)

# 在该文件中加载另一个cmake文件，但此时该文件并不在这个目录的子目录里
add_subdirectory(${HELLO_WORLD_DIR_ROOT}/thirdpart/googletest-1.15.2 googletest)

add_executable(test_hello ${CMAKE_CURRENT_SOURCE_DIR}/test_hello.cpp)
add_executable(test_world ${CMAKE_CURRENT_SOURCE_DIR}/test_world.cpp)
# 指定目标的头文件搜索的路径
target_include_directories(test_hello PUBLIC ${HELLO_WORLD_DIR_ROOT}/thirdpart/googletest-1.15.2/googletest/include/gtest)
target_include_directories(test_hello PUBLIC ${HELLO_WORLD_DIR_ROOT})
target_link_libraries(test_hello PUBLIC hellolib gtest gtest_main)

add_test(NAME test_hello
            COMMAND test_hello)


target_include_directories(test_world PUBLIC ${HELLO_WORLD_DIR_ROOT}/thirdpart/googletest-1.15.2/googletest/include/gtest)
target_include_directories(test_world PUBLIC ${HELLO_WORLD_DIR_ROOT})
target_link_libraries(test_world PUBLIC worldlib gtest gtest_main)

add_test(NAME test_world
            COMMAND test_world)

