#include <iostream>
#include <bit>
#include <limits>

using namespace std;

inline void solve() {
    unsigned int n, ans, firstOnePos;
    cin >> n;
    firstOnePos = countl_zero(n) + 1;
    ans = ~n;
    ans = ans | (ans >> 1) | (ans << 1);
    ans = ans << firstOnePos >> firstOnePos;
    if (ans >= n || (ans & n) == 0) {
        cout << -1 << '\n';
        return;
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}