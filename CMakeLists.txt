cmake_minimum_required(VERSION 3.14)
project(Graph LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options("-Wall" "-g")

list(
    APPEND SOURCES
    src/exception.hpp
    src/graph.hpp src/graph.cpp
    src/algorithms.hpp src/algorithms.cpp
)

# Making an executable
add_executable(
    main
    # SOURCES
    src/main.cpp
    ${SOURCES}
)

# Making a library
add_library(
    graph STATIC
    # SOURCES
    ${SOURCES}
)

# Dependencies

# GoogleTest (C++14 and above)
#include(FetchContent)
#FetchContent_Declare(
#    googletest
#    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
#)
