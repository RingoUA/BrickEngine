cmake_minimum_required(VERSION 3.1)
project(BrickEngine CXX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/)

set(SRC src/window.cpp)

add_library(BrickEngine ${SRC})

target_link_libraries(BrickEngine ${CONAN_LIBS})
target_include_directories(BrickEngine PUBLIC ${INC_DIR})

install(FILES include/BrickEngine.hpp include/window.hpp DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})