cmake_minimum_required(VERSION 2.8.12)
project(main)

add_definitions("-std=c++17")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(INC include/window.hpp)

set(SRC src/window.cpp)

add_executable(main ${INC} ${SRC})
target_link_libraries(main ${CONAN_LIBS})