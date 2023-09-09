#include <vector>
#include <utility>

namespace helper {

struct PriorityQueue {
    // id -> i
    std::vector<int> mapping;
    // i -> value
    std::vector<std::pair<int, int>> data;

    PriorityQueue() :
        mapping(std::vector<int>()),
        data(std::vector<std::pair<int, int>>()) {}
    void push(int id, int value);
    std::pair<int, int> pop();
    void decreaseKey(int id, int value);
};

}
