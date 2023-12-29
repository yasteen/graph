#include <graph/algorithms.hpp>
#include <graph/graph.hpp>
#include <gtest/gtest.h>
#include <limits>

inline void add_vertices(graph::graph& g, int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        g.add_vert(i, 0);
    }
}
inline void add_edges(graph::graph& g, int v_a, int v_b, int data) {
    g.add_edge(v_a, v_b, data);
    g.add_edge(v_b, v_a, data);
}

inline void expect_result(graph::dijkstra_result & r, int i, int dist, std::optional<int> prev) {
    EXPECT_EQ(r[i].first, dist);
    EXPECT_EQ(r[i].second, prev);
}

class DijkstraTest : public testing::Test {
protected:
    graph::graph g;
    DijkstraTest() { g = graph::graph(); }
};

TEST_F(DijkstraTest, TestDijkstra_Simple) {
    add_vertices(g, 5);
    add_edges(g, 0, 1, 5);
    add_edges(g, 0, 2, 15);
    add_edges(g, 1, 2, 6);
    add_edges(g, 2, 3, 2);

    graph::dijkstra_result r = graph::dijkstra(g, 0);
    EXPECT_EQ(r.size(), 5);

    expect_result(r, 0, 0, std::nullopt);
    expect_result(r, 1, 5, 0);
    expect_result(r, 2, 11, 1);
    expect_result(r, 3, 13, 2);
    expect_result(r, 4, std::numeric_limits<int>::max(), std::nullopt);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
