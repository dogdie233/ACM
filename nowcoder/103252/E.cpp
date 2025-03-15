#include <iostream>
#include <stdint.h>
#include <vector>
#include <limits>
#include <cmath>

typedef int64_t sumType;

struct Node {
    sumType sum;
};

int n;
std::vector<std::vector<int>> connections;
std::vector<Node> nodes;

sumType sumDfs(int fromIndex, int currentIndex) {
    sumType sum = 0;
    for (int i = 0; i < connections[currentIndex].size(); i++) {
        int nextIndex = connections[currentIndex][i];
        if (nextIndex == fromIndex) {
            continue;
        }
        sum += std::abs(currentIndex - nextIndex);
        sum += sumDfs(currentIndex, nextIndex);
    }
    return nodes[currentIndex].sum = sum;
}

sumType sum = 0, ans = std::numeric_limits<sumType>::max();

void cutDfs(int fromIndex, int currentIndex) {
    sumType part1, part2, abs;
    for (int i = 0; i < connections[currentIndex].size(); i++) {
        int nextIndex = connections[currentIndex][i];
        if (nextIndex == fromIndex) {
            continue;
        }
        part1 = nodes[nextIndex].sum;
        part2 = sum - part1 - std::abs(nextIndex - currentIndex);
        ans = std::min(ans, std::abs(part2 - part1));
        cutDfs(currentIndex, nextIndex);
    }
}

int main() {
    std::cin >> n;
    connections.resize(n + 1);
    nodes.resize(n + 1);

    for (int i = 1; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }

    sum = sumDfs(1, 1);
    cutDfs(1, 1);

    return std::cout << ans, 0;
}