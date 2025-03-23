#include <iostream>
#include <stdint.h>

using namespace std;

inline void solve() {
    int32_t n, k;
    int64_t num, sum = 0;
    cin >> n >> k;
    for (auto i = 0; i < n; i++) {
        cin >> num;
        if (num > 0) {
            sum += num;
        }
    }
    cout << sum << '\n';
}

int main() {
    int T;
    cin >> T;
    while (T--)
        solve();
}