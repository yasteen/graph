#include <graph/graph.hpp>
#include <graph/exception.hpp>
#include <iostream>

namespace graph {

bool graph::is_adjacent(int from, int to) {
    const vertex& v = adj[from];
    const std::list<edge>& neighbours = v.neighbours;

    for (const edge& edge : neighbours) {
        if (to == edge.to) {
            return true;
        }
    }

    return false;
}

std::list<edge>& graph::neighbours(int v) { return adj[v].neighbours; }

void graph::add_edge(int from, int to, int data) {
    adj[from].neighbours.push_back(edge(to, data));
    num_edges++;
}

void graph::rm_edge(int from, int to) {
    const std::list<edge>& neighbours = adj[from].neighbours;

    for (const edge& edge : neighbours) {
        if (to == edge.to) {
            adj[from].neighbours.remove(edge);
            num_edges--;
            return;
        }
    }

    throw edge_exception(from, to);
}

void graph::add_vert(int v, int data) { adj.insert(std::pair(v, vertex(v, data))); }

void graph::rm_vert(int v) {
    adj.erase(v);
    for (auto& [key, vertex] : adj) {
        for (const edge& edge : vertex.neighbours) {
            if (edge.to == v) {
                vertex.neighbours.remove(edge);
                num_edges--;
            }
        }
    }
}

const vertex& graph::get_vert(int v) { return adj[v]; }

void graph::set_vert(int v, int data) { adj[v].data = data; }

const edge& graph::get_edge(int from, int to) {
    for (const edge& edge : adj[from].neighbours) {
        if (edge.to == to) {
            return edge;
        }
    }
    throw edge_exception(from, to);
}

void graph::set_edge(int from, int to, int data) {
    for (edge& edge : adj[from].neighbours) {
        if (edge.to == to) {
            edge.data = data;
        }
    }
    throw edge_exception(from, to);
}

}
