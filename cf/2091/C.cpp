#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

inline void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "-1\n";
        return;
    }

    for (auto i = 1; i <= n; i += 2) {
        cout << i << ' ';
    }
    for (auto i = 2; i <= n; i += 2) {
        cout << i << ' ';
    }
    cout << '\n';
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