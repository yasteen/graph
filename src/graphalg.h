#pragma once
#include "graph.h"

namespace graphalg {

struct DijkstraResult {
    std::list<int> dist;
    std::list<int> prev;

    DijkstraResult(std::list<int> dist, std::list<int> prev) :
        dist(dist), prev(prev) {}
};

template <typename V>
DijkstraResult dijkstra(graph::Graph<V, int> g, int source);

}
