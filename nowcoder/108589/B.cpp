// Nowcoder Compiler: C++（clang++18）
#include <iostream>

using namespace std;

char ch[1000][1000];

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int n, m, wx, wy;
    cin >> n >> m;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> ch[y][x];
            if (ch[y][x] == '#') {
                wx = x;
                wy = y;
            }
        }
    }

    if (wx != 0 && wy != n - 1) {
        for (int y = 1; y < n; y++) {
            cout << 'S';
        }
        for (int x = 1; x < m; x++) {
            cout << 'D';
        }
    } else {
        for (int x = 1; x < m; x++) {
            cout << 'D';
        }
        for (int y = 1; y < n; y++) {
            cout << 'S';
        }
    }

    return 0;
}