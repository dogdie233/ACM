// Nowcoder Compiler: C++（clang++18）
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>> conns(n + 1, vector<int>());
    unordered_set<int> vSet;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        conns[u].push_back(v);
        conns[v].push_back(u);
    }
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        vSet.insert(num);
    }
    if (n == 1 || m == 1) {
        return cout << "0" << endl, 0;
    }

    auto foot = find_if(conns.cbegin() + 1, conns.cend(), [&](const vector<int>& v) {
        return v.size() == 1;
    }) - conns.begin();

    auto ans = vector<pair<int, int>>();

    auto dfs = [&](auto&& self, int now, int from) -> void {
        if (vSet.count(now)) {
            ans.push_back({now, from});
        }
        for (auto& next : conns[now]) {
            if (next == from) {
                continue;
            }
            self(self, next, now);
        }
    };

    dfs(dfs, foot, foot);
    ans.erase(ans.begin());

    cout << ans.size();
    for (auto& p : ans) {
        cout << endl << p.first << " " << p.second;
    }


    return 0;
}