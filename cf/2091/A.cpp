#include <iostream>

using namespace std;

inline void solve() {
    int req[] = { 3, 1, 2, 1, 0, 1, 0, 0, 0, 0 };
    int n, num, ans = -1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        req[num]--;
        if (ans != -1) {
            continue;
        }
        bool ok = true;
        for (int j = 0; j < 10; j++) {
            if (req[j] > 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans = i + 1;
        }
    }
    cout << (ans == -1 ? 0 : ans) << '\n';
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