cmake_minimum_required(VERSION 2.8.12)
project(main)

add_definitions("-std=c++11")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(INC_DIR ../include/)


set(SRC ${SRC} 
../src/window.cpp
main.cpp)

add_executable(main ${SRC})
target_link_libraries(main ${CONAN_LIBS})
target_include_directories(main PRIVATE ${INC_DIR})