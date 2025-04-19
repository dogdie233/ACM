// Nowcoder Compiler: C++（clang++18）
#include <iostream>
#include <stdint.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int64_t pow(int64_t b, int64_t e, int64_t m) {
    int64_t ans = 1;
    while (e) {
        if (e & 1) {
            ans = (ans * b) % m;
        }
        b = (b * b) % m;
        e >>= 1;
    }
    return ans;
}

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int64_t n, k, qwq;
    cin >> n >> k;
    if ((n - k) % 2 == 0) {
        cout << pow(2, n - k + 1, MOD) << endl;
    } else {
        cout << "wawawawawa" << endl;
    }
    return 0;
}