cmake_minimum_required(VERSION 3.18)
project(hello)

set(HELLO_SRC hello.cpp hello1.cpp)

add_library(hellolib SHARED ${HELLO_SRC})