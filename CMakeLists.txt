cmake_minimum_required(VERSION 3.16)
project(Graph LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options("-Wall" "-g")

add_subdirectory(src)
add_subdirectory(test)

# Making an executable
add_executable(main src/main.cpp)
target_link_libraries(main graph)

