#pragma once
#include <iterator>
#include <list>
#include <unordered_map>

namespace graph {

struct edge {
    int to;
    int data;

    [[nodiscard]] edge()
        : edge { 0, 0 }
    {
    }
    [[nodiscard]] explicit edge(int to, int data)
        : to { to }
        , data { data }
    {
    }
    bool operator==(const edge& rhs) const { return to == rhs.to; }
};

struct vertex {
    int id;
    std::list<edge> neighbours;
    int data;
    [[nodiscard]] vertex()
        : vertex { 0, 0 }
    {
    }
    [[nodiscard]] explicit vertex(int id, int data)
        : id { id }
        , neighbours { {} }
        , data { data }
    {
    }
    bool operator==(const vertex& rhs) const { return id == rhs.id; }
};

class _graph {

protected:
    // Returns true if there is an edge from the first node to the second, false
    // otherwise.
    [[nodiscard]] virtual bool is_adjacent(int from, int to) = 0;
    // Returns the neighbours for a given node.
    [[nodiscard]] virtual std::list<edge>& neighbours(int v) = 0;

    // Adds an edge from the first node to the second. Returns true on success.
    virtual void add_edge(int from, int to, int data) = 0;
    // Removes an edge from the first node to the second. Returns true on success.
    virtual void rm_edge(int from, int to) = 0;
    // Adds a new vertex. Returns true on success.
    virtual void add_vert(int v, int data) = 0;
    // Removes the vertex associated with the index. Returns true on success.
    virtual void rm_vert(int v) = 0;

    // Returns the data for the given vertex
    [[nodiscard]] virtual const vertex& get_vert(int v) = 0;
    // Sets the data for the given vertex
    virtual void set_vert(int v, int data) = 0;

    // Returns the data for the given edge
    [[nodiscard]] virtual const edge& get_edge(int from, int to) = 0;
    // Sets the data for the given edge
    virtual void set_edge(int from, int to, int data) = 0;

    virtual unsigned long node_size() = 0;
    virtual unsigned long edge_size() = 0;
};

class graph : public _graph {
private:
    std::unordered_map<int, vertex> adj;
    int num_edges;

public:
    [[nodiscard]] bool is_adjacent(int from, int to);
    [[nodiscard]] std::list<edge>& neighbours(int v);

    void add_edge(int from, int to, int data);
    void rm_edge(int from, int to);
    void add_vert(int v, int data);
    void rm_vert(int v);

    [[nodiscard]] const vertex& get_vert(int v);
    void set_vert(int v, int data);

    [[nodiscard]] const edge& get_edge(int from, int to);
    void set_edge(int from, int to, int data);

    unsigned long node_size() { return adj.size(); }
    unsigned long edge_size() { return num_edges; }
    auto begin() { return adj.begin(); }
    auto end() { return adj.end(); }
};

} // namespace graph
