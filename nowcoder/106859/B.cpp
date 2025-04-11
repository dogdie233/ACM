// Nowcoder Compiler: C++（clang++18）
#include <iostream>

using namespace std;

bool used[100000];

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int n, val;
    long long ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        if (val > n || used[val]) continue;
        used[val] = true;
        ans += val;
    }
    cout << ans;
    return 0;
}