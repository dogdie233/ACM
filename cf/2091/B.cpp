#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

inline void solve() {
    int n, x, ans = 0;
    cin >> n >> x;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    sort(a.begin(), a.end(), greater<int>());
    int playerCount = 0;
    for (auto ai : a) {
        playerCount++;
        auto ability = ai * playerCount;
        if (ability >= x) {
            ans++;
            playerCount = 0;
        }
    }
    cout << ans << '\n';
}

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}