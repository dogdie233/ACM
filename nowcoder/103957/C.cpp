#include <iostream>

typedef long long num_t;

using namespace std;

inline void solve() {
    num_t n, m, k, q;
    cin >> n >> m >> k >> q;
    if (m * (k - 1) < q) {
        cout << "No" << '\n';
        return;
    }

    cout << ((n - q) % k == 0 ? "Yes" : "No") << '\n';
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}