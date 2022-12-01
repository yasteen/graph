#include "graph.h"
#include <iostream>

using namespace graph;

// ===== Matrix Graph =====

template <typename V, typename E>
MatrixGraph<V, E>::MatrixGraph(
        std::vector<V> vertexData,
        std::vector<E> edgeData,
        std::vector<std::pair<int, int>> edges
) : Graph<V, E>::Graph(vertexData, edgeData) {
    size_t size = vertexData.size();
    graph = std::vector<std::vector<bool>>(size, std::vector<bool>(size, false));
    for (auto edge : edges)
        graph[edge.first][edge.second] = 1;
}

template <typename V, typename E>
std::list<int> MatrixGraph<V, E>::getNeighbours(int node) {
    std::list<int> neighbours;
    for (size_t i = 0; i < graph[node].size(); i++)
        neighbours.push_back(i);
    return neighbours;
}

template <typename V, typename E>
bool MatrixGraph<V, E>::isNeighbour(int a, int b) {
    return graph[a][b];
}

// ===== List Graph =====

template <typename V, typename E>
ListGraph<V, E>::ListGraph(
        std::vector<V> vertexData,
        std::vector<E> edgeData,
        std::vector<std::pair<int, int>> edges
) : Graph<V, E>::Graph(vertexData, edgeData) {
    size_t size = vertexData.size();
    graph = std::vector<std::list<int>>(size, std::list<int>());
    for (auto edge : edges)
        graph[edge.first].push_back(edge.second);
}

template <typename V, typename E>
std::list<int> ListGraph<V, E>::getNeighbours(int node) {
    return graph[node];
}

template <typename V, typename E>
bool ListGraph<V, E>::isNeighbour(int a, int b) {
    for (int i : graph[a])
        if (i == b) return true;
    return false;
}

