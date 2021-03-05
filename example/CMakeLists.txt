cmake_minimum_required(VERSION 3.20.0)
project(main)


include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_compile_definitions(_ITERATOR_DEBUG_LEVEL=0)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDLL")

add_executable(main main.cpp)
target_link_libraries(main ${CONAN_LIBS})