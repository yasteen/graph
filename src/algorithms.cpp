#include <graph/algorithms.hpp>
#include <limits>
#include <optional>
#include <queue>

namespace graph {

// Map from vertex id -> (distance, previous vertex id)
using dijkstra_result = std::unordered_map<int, std::pair<int, std::optional<int>>>;
dijkstra_result dijkstra(graph g, int source) {
    // Pair (distance, vertex id)
    using pq_entry = std::pair<int, int>;
    dijkstra_result m;
    std::priority_queue<pq_entry, std::vector<pq_entry>, std::greater<pq_entry>> q;

    // Initialize infinite distance for each vertex, and shove into priority queue
    for (const auto& [v, _] : g) {
        m[v] = { std::numeric_limits<int>::max(), std::nullopt };
        q.emplace(pq_entry(m[v].first, v));
    }
    m[source].first = 0;

    while (!q.empty()) {
        const auto & [dist, u] =  q.top();

        for (const edge & e : g.neighbours(u)) {
            int alt = dist + g.get_edge(u, e.to).data;
            if (alt < m[e.to].first) {
                m[e.to].first = alt;
                m[e.to].second = u;
                q.pop();
            }
        }
    }

    return m;
    }
}
