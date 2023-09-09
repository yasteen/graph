#pragma once
#include <vector>
#include <list>
#include <utility>
#include <optional>

namespace graph {

template <typename V, typename E>
struct Graph {
    Graph(
        std::vector<V> vertexData,
        std::vector<E> edgeData
    ) : vertexData(vertexData), edgeData(edgeData) {}
    virtual std::list<std::pair<int, int>> getNeighbours(int node) = 0;
    virtual bool isNeighbour(int a, int b) = 0;
    virtual std::optional<E> getEdge(int a, int b) = 0;

    std::vector<V> vertexData;
    std::vector<E> edgeData;
};

template <typename V, typename E>
struct MatrixGraph: public Graph<V, E> {
    MatrixGraph(
        std::vector<V> vertexData,
        std::vector<E> edgeData,
        std::vector<std::pair<int, int>> edges
    );

    std::list<std::pair<int, int>> getNeighbours(int node);
    bool isNeighbour(int a, int b);
    virtual std::optional<E> getEdge(int a, int b);
protected:
    // Row: origin vertex; Col: dest vertex
    std::vector<std::vector<int>> graph;
};

template <typename V, typename E>
struct ListGraph: public Graph<V, E> {
    ListGraph(
        std::vector<V> vertexData,
        std::vector<E> edgeData,
        std::vector<std::pair<int, int>> edges
    );

    std::list<std::pair<int, int>> getNeighbours(int node);
    bool isNeighbour(int a, int b);
    std::optional<E> getEdge(int a, int b);
protected:
    // graph[u] = pair(edge, v)
    std::vector<std::list<std::pair<int, int>>> graph;
};

}

#include "graph.cpp"
