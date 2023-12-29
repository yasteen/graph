list(
    APPEND SOURCES
    graph.cpp
    algorithms.cpp
)

add_library(graph ${SOURCES})
target_include_directories(graph PUBLIC include)
