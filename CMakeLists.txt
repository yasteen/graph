cmake_minimum_required(VERSION 3.1)
project(Graph LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options("-Wall" "-g" )

# Making an executable
add_executable(main
    src/main.cpp
    src/graph.h
    #src/graph.cpp
    src/graphalg.h
    src/graphalg.cpp
)

# Making a library
# add_library(main STATIC main.cpp)
