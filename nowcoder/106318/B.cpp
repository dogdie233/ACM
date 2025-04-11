// Nowcoder Compiler: C++（clang++18）
#include <iostream>

using namespace std;

bool check(int x1, int y1, int x2, int y2, int x3, int y3) {
    if (x1 == -x2 && x3 == 0) return true;
    if (y1 == -y2 && y3 == 0) return true;
    return false;
}

inline void solve() {
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    if (check(xa, ya, xb, yb, xc, yc) || check(xa, ya, xc, yc, xb, yb) || check(xb, yb, xc, yc, xa, ya)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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