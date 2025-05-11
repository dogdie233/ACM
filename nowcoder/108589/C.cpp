// Nowcoder Compiler: C++（clang++18）
#include <iostream>

using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int n;
    cin >> n;
    if (n < 3) {
        return cout << "-1\n", 0;
    }
    cout << n;
    for (int i = 1; i < n; i++) {
        cout << ' ' << i;
    }
    return cout << '\n', 0;
}