// Nowcoder Compiler: C++（clang++18）
#include <iostream>
#include <vector>

using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int n, x, val;
    cin >> n >> x;
    auto mp = vector<vector<int>>(n);
    for (int i = 0; i < n; i++) {
        cin >> val;
        mp[val - 1].push_back(i);
    }

    auto walked = vector<bool>(n, false);
    auto dfs = [&](auto&& self, int hit) -> bool {
        if (walked[hit]) return true;
        walked[hit] = true;
        for (auto& i : mp[hit]) {
            if (self(self, i)) return true;
        }
        return false;
    };

    cout << (dfs(dfs, x - 1) ? "Yes" : "No");
    return 0;
}