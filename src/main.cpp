#include "graph.hpp"
#include <iostream>

int main() {
    std::cout << "Hello there" << std::endl;
    graph::graph g = graph::graph();
    g.add_vert(0, 10);
    g.add_vert(1, 20);
    g.add_vert(2, 30);
    g.add_edge(0, 1, 30);
    g.add_edge(1, 2, 50);

    for (int i = 0; i < 3; i++) {
        const auto& neighbours = g.neighbours(i);
        std::cout << "VERTEX" << i << ": ";
        for (const auto& edge : neighbours) {
            std::cout << "{" << edge.to << ", " << edge.data << "}, ";
        }
        std::cout << std::endl;
    }

    std::cout << "Matrix Graph" << std::endl;
    std::cout << "(0, 1): " << g.is_adjacent(0, 1) << std::endl;
    std::cout << "(1, 2): " << g.is_adjacent(1, 2) << std::endl;
    std::cout << "(0, 2): " << g.is_adjacent(0, 2) << std::endl;
    std::cout << "(1, 0): " << g.is_adjacent(1, 0) << std::endl;
    std::cout << "(2, 1): " << g.is_adjacent(2, 1) << std::endl;
    std::cout << "(2, 0): " << g.is_adjacent(2, 0) << std::endl;
}
