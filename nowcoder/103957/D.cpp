#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

using namespace std;

vector<vector<int>> connections;

int main() {
    int n;
    cin >> n;
    connections.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        connections[u].push_back(v);
        connections[v].push_back(u);
    }

    if (n == 2) {
        return cout << "1 1", 0;
    }
    
    auto& mostEdgeNode = *max_element(connections.cbegin(), connections.cend(), [](const vector<int>& a, const vector<int>& b) {
        return a.size() < b.size();
    });
    auto maxSize = mostEdgeNode.size();
    auto rootIt = connections.begin() + 1;
    for (auto nodeIt = connections.begin() + 1; nodeIt != connections.end(); nodeIt++) {
        if (nodeIt->size() < maxSize) {
            rootIt = nodeIt;
            break;
        }
    }

    cout << maxSize - 1 << ' ' << (rootIt - connections.begin()) << '\n';
    return 0;
}