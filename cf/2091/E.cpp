#include <iostream>
#include <stdint.h>

using namespace std;

bool isNotPrimes[1000001];

inline void init() {
    for (int i = 2; i * i <= 1000000; i++) {
        if (!isNotPrimes[i]) {
            for (int j = i * i; j <= 1000000; j += i) {
                isNotPrimes[j] = true;
            }
        }
    }
}

inline void solve() {
    int64_t n, ans = 0;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (isNotPrimes[i]) continue;
        ans += n / i;
    }
    cout << ans << '\n';
}

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    init();
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}