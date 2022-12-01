cmake_minimum_required(VERSION 3.1)

project(Graph LANGUAGES CXX)

add_compile_options("-Wall" "-g")

# Making an executable
add_executable(main
    src/main.cpp
    src/graph.h
    #src/graph.cpp
)

# Making a library
# add_library(main STATIC main.cpp)
