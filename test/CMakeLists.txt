# GoogleTest (C++14 and above)
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.14.0
)

FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(dijkstra_test dijkstra_test.cpp)

target_link_libraries(dijkstra_test
PRIVATE
    GTest::GTest
    graph)

add_test(dijkstra_gtest dijkstra_test)
