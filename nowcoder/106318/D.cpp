// Nowcoder Compiler: C++（clang++18）
#include <iostream>
#include <stdint.h>

using namespace std;

inline void solve() {
    uint32_t x, ans = 0xffffffff;
    cin >> x;

    for (int i = 0; x != 0; i++, x >>= 1) {
        if (x & 1) continue;
        ans = 1 << i;
        break;
    }

    cout << static_cast<int32_t>(ans) << '\n';
}

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}