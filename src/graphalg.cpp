#include <limits>
#include <queue>
#include <utility>

#include "graphalg.h"

using namespace graphalg;

template <typename V>
DijkstraResult dijkstra(graph::Graph<V, int> g, int source) {
    int inf = std::numeric_limits<int>::max();
    std::priority_queue<std::pair<int, int>> queue;
    std::vector<int> dist, prev;
    for (int v = 0; v < g.vertexData.size(); v++) {
        dist.push_back(inf);
        prev.push_back(-1);
        if (v != source) queue.push(std::pair<int, int>(dist[v], v));
    }
    dist[source] = 0;
    queue.push(std::pair<int, int>(dist[source], source));

    while (!queue.empty()) {
        std::pair<int, int> u = queue.pop();
        for (int v : g.getNeighbours(u.second)) {
            int alt = dist[u.second] + g.getEdge(u, v);
            if (alt < dist[v]) {
                dist[v] = alt;
                prev[v] = u.first;
                //queue.decrease_value
            }
        }
    }
    return DijkstraResult(dist, prev);
}

