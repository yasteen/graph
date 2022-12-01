#pragma once
#include <vector>
#include <list>
#include <utility>

namespace graph {

template <typename V, typename E>
class Graph {
public:
    Graph(
        std::vector<V> vertexData,
        std::vector<E> edgeData
    ) : vertexData(vertexData), edgeData(edgeData) {}
    virtual std::list<int> getNeighbours(int node) = 0;
    virtual bool isNeighbour(int a, int b) = 0;

protected:
    std::vector<V> vertexData;
    std::vector<E> edgeData;
};

template <typename V, typename E>
class MatrixGraph: public Graph<V, E> {
public:
    MatrixGraph(
        std::vector<V> vertexData,
        std::vector<E> edgeData,
        std::vector<std::pair<int, int>> edges
    );
   
    std::list<int> getNeighbours(int node);
    bool isNeighbour(int a, int b);
protected:
    // Row: origin vertex; Col: dest vertex
    std::vector<std::vector<bool>> graph;
};

template <typename V, typename E>
class ListGraph: public Graph<V, E> {
public:
    ListGraph(
        std::vector<V> vertexData,
        std::vector<E> edgeData,
        std::vector<std::pair<int, int>> edges
    );

    std::list<int> getNeighbours(int node);
    bool isNeighbour(int a, int b);
protected:
    std::vector<std::list<int>> graph;
};

}

#include "graph.cpp"
