// Nowcoder Compiler: C++（clang++18）
#include <iostream>

using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        cout << min(5, val - 1 + (i == 0 ? 2 : 0)) << ' ';
    }
    return 0;
}