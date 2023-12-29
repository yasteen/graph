#include <graph/algorithms.hpp>
#include <limits>
#include <optional>
#include <queue>

namespace graph {

dijkstra_result dijkstra(graph g, int source) {
    // Pair (distance, vertex id)
    using pq_entry = std::pair<int, int>;
    dijkstra_result result;
    std::priority_queue<pq_entry, std::vector<pq_entry>, std::greater<pq_entry>> q;

    // Initialize infinite distance for each vertex, and shove into priority queue
    for (const auto& [v, _] : g) {
        result[v] = { std::numeric_limits<int>::max(), std::nullopt };
    }
    result[source].first = 0;
    q.emplace(pq_entry(result[source].first, source));

    while (!q.empty()) {
        const auto& [dist, u] = q.top();
        q.pop();

        for (const edge& e : g.neighbours(u)) {
            int alt = dist + g.get_edge(u, e.to).data;
            if (alt < result[e.to].first) {
                result[e.to].first = alt;
                result[e.to].second = u;
                q.emplace(pq_entry(alt, e.to));
            }
        }
    }

    return result;
}

}
