#include <iostream>
#include <vector>

using namespace std;

const int64_t MOD = 1e9 + 7;

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int64_t n, val, ans = 0, sum = 0, xorSum = 0;
    cin >> n;
    while (n--) {
        cin >> val;
        xorSum ^= val;
        ans = (sum * 2 + xorSum) % MOD;
        sum = (sum + ans) % MOD;
    }
    cout << (ans % MOD) << endl;
    return 0;
}