#pragma once
#include "graph.hpp"
#include <optional>
#include <unordered_map>

namespace graph {

// Map from vertex id -> (distance, previous vertex id)
using dijkstra_result = std::unordered_map<int, std::pair<int, std::optional<int>>>;

dijkstra_result dijkstra(graph g, int source);

}
