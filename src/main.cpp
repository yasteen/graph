#include <iostream>
#include "graph.h"

int main() {
    std::cout << "Hello there" << std::endl;
    std::vector<int> vectorData = { 0, 1, 2 };
    std::vector<int> edgeData = { NULL, NULL, NULL };
    std::vector<std::pair<int, int>> edges = { { 0, 1 }, {1, 2} };

    graph::MatrixGraph<int, int> mg(vectorData, edgeData, edges);
    std::cout << "Matrix Graph" << std::endl;
    std::cout << "(0, 1): " << mg.isNeighbour(0, 1) << std::endl;
    std::cout << "(1, 2): " << mg.isNeighbour(1, 2) << std::endl;
    std::cout << "(0, 2): " << mg.isNeighbour(0, 2) << std::endl;

    graph::ListGraph<int, int> lg(vectorData, edgeData, edges);
    std::cout << "(0, 1): " << lg.isNeighbour(0, 1) << std::endl;
    std::cout << "(1, 2): " << lg.isNeighbour(1, 2) << std::endl;
    std::cout << "(0, 2): " << lg.isNeighbour(0, 2) << std::endl;
    return 0;
}
