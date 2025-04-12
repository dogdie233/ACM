#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Node {
    int num;
    vector<int> children;
};

vector<Node> tree;

set<int> query(int idx, int maxx) {
    set<int> result;
    if (tree[idx].children.size() == 0) {
        result.insert(tree[idx].num);
        return result;
    }
    maxx = min(maxx, tree[idx].num);
    result.insert(0);
    vector<int> temp;
    for (int childIdx : tree[idx].children) {
        temp.clear();
        auto childPossible = query(childIdx, maxx);
        for (auto v : childPossible) {
            for (auto w : result) {
                auto addValue = v + w;
                if (addValue > maxx) {
                    break;
                }
                temp.push_back(addValue);
            }
        }
        result.insert(temp.begin(), temp.end());
    }
    return result;
}

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int n;
    cin >> n;
    tree = vector<Node>(n);
    for (auto& node : tree) {
        cin >> node.num;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        tree[u - 1].children.push_back(v - 1);
    }

    auto ans = *query(0, 0x7fffffff).crbegin();
    cout << ans;
    return 0;
}