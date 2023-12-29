#pragma once

#include <stdexcept>
#include <string>
namespace graph {

class vertex_exception : public std::runtime_error {
public:
    [[nodiscard]] explicit vertex_exception(int v)
        : std::runtime_error { "Missing vertex " + std::to_string(v) } { }
};

class edge_exception : public std::runtime_error {
public:
    [[nodiscard]] explicit edge_exception(int from, int to)
        : std::runtime_error { "Missing edge " + std::to_string(from) + ", "
            + std::to_string(to) } { }
};

}
