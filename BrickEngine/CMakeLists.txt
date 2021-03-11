cmake_minimum_required(VERSION 3.1)
project(BrickEngine CXX)


include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_compile_definitions(_ITERATOR_DEBUG_LEVEL=0)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDLL")

set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/)
set(PRIVATE_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/inc/)

set(SRC src/Window.cpp
        src/WindowOpenGL.cpp
        src/Log.cpp
)

add_library(BrickEngine ${SRC})

target_link_libraries(BrickEngine ${CONAN_LIBS})
target_include_directories(BrickEngine PUBLIC ${INC_DIR})
target_include_directories(BrickEngine PRIVATE ${PRIVATE_INC_DIR})

install(FILES include/BrickEngine.hpp
              include/Window.hpp
              include/Log.hpp

        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})