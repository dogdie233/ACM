#include <iostream>

typedef long long num_t;

using namespace std;

inline void solve() {
    num_t n, m, k;
    cin >> n >> m >> k;
    
    auto check = [&](num_t value) -> bool {
        auto groupPerLine = m / (value + 1);
        auto chairPerLine = groupPerLine * value;
        chairPerLine += m % (value + 1);
        auto totalChair = chairPerLine * n;
        return totalChair >= k;
    };

    num_t l = 0, r = m;
    while (l < r) {
        auto mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << '\n';
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