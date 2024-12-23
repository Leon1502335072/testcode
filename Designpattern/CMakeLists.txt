cmake_minimum_required(VERSION 3.5)
project(designpattern)

# 输出make时的详细信息
set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(./)

# 后面路径需要加双引号 因为我是在build中执行的cmake .. 所以需要退两次
set(EXECUTABLE_OUTPUT_PATH "../../bin/")


add_executable(317Iterator 317Iterator.cpp MyList.cpp)
add_executable(318Mediator 318Mediator.cpp)
add_executable(320Observer 320Observer.cpp NewsAgency.cpp)
add_executable(322State 322State.cpp)
add_executable(324Visitor 324Visitor.cpp)