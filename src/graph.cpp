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
    graph = std::vector<std::vector<int>>(size, std::vector<int>(size, -1));
    for (size_t i = 0; i < edges.size(); i++)
        graph[edges[i].first][edges[i].second] = i;
}

template <typename V, typename E>
std::list<std::pair<int, int>> MatrixGraph<V, E>::getNeighbours(int node) {
    std::list<std::pair<int, int>> neighbours;
    for (size_t i = 0; i < graph[node].size(); i++)
        neighbours.push_back(std::pair<int, int>(graph[node][i], i));
    return neighbours;
}

template <typename V, typename E>
bool MatrixGraph<V, E>::isNeighbour(int a, int b) {
    return graph[a][b] != -1;
}

template <typename V, typename E>
std::optional<E> MatrixGraph<V, E>::getEdge(int a, int b) {
    for (int i : graph[a])
        if (i == b) return this->edgeData[i];
    return NULL;
}

// ===== List Graph =====

template <typename V, typename E>
ListGraph<V, E>::ListGraph(
        std::vector<V> vertexData,
        std::vector<E> edgeData,
        std::vector<std::pair<int, int>> edges
) : Graph<V, E>::Graph(vertexData, edgeData) {
    size_t size = vertexData.size();
    graph = std::vector<std::list<std::pair<int, int>>>(
            size,
            std::list<std::pair<int, int>>()
    );
    for (size_t i = 0; i < edges.size(); i++)
        graph[edges[i].first].push_back(std::pair<int, int>(i, edges[i].second));
}

template <typename V, typename E>
std::list<std::pair<int, int>> ListGraph<V, E>::getNeighbours(int node) {
    return graph[node];
}

template <typename V, typename E>
bool ListGraph<V, E>::isNeighbour(int a, int b) {
    for (auto link : graph[a])
        if (link.second == b) return true;
    return false;
}

template <typename V, typename E>
std::optional<E> ListGraph<V, E>::getEdge(int a, int b) {
    for (auto link : graph[a])
        if (link.second == b) return this->edgeData[link.first];
    return NULL;
}

