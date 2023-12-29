#pragma once
#include "graph.hpp"
#include <optional>
#include <unordered_map>

namespace graph {

std::unordered_map<int, std::pair<int, std::optional<int>>> dijkstra(
    graph g, int source);

}
