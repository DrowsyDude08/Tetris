cmake_minimum_required(VERSION 3.26)
project(Tetris)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.6 COMPONENTS system window graphics REQUIRED)
if(NOT DEFINED ENV{SFML_ROOT})
  message(FATAL_ERROR "is not found")
else()
  set(SFML_DIR "$ENV{SFML_ROOT}/lib/cmake/SFML")
endif()

find_package(SFML 2.6 COMPONENTS system window graphics REQUIRED)

add_executable(Tetris
Source/Main.cpp)

target_link_libraries(Tetris
sfml-system
sfml-window
sfml-graphics)

install(TARGETS Tetris DESTINATION bin)
install(DIRECTORY Source/ DESTINATION include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

message(STATUS "CMake is using the following compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "CMake is using the following flags: ${CMAKE_CXX_FLAGS}")