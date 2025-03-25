#include <iostream>

using namespace std;

inline void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    auto check = [&](int value) -> bool {
        auto groupPerLine = m / (value + 1);
        auto chairPerLine = groupPerLine * value;
        chairPerLine += m % (value + 1);
        auto totalChair = chairPerLine * n;
        return totalChair >= k;
    };

    int l = 0, r = m;
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