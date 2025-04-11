// Nowcoder Compiler: C++（clang++18）
#include <iostream>
#include <stdint.h>
#include <vector>
#include <limits>

typedef int64_t coin_t;

using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    coin_t n, k;
    cin >> n >> k;
    auto world1 = vector<coin_t>(n);
    auto world2 = vector<coin_t>(n);
    for (auto& i : world1) {
        cin >> i;
    }
    for (auto& i : world2) {
        cin >> i;
    }

    coin_t dp1 = world1[0], dp2 = numeric_limits<coin_t>::min() + k;
    bool world2Unlocked = false;
    for (int i = 1; i < n; i++) {
        if (!world2Unlocked && dp1 >= k) {
            world2Unlocked = true;
        }

        auto save1 = dp1;
        auto save2 = dp2;

        if (world2Unlocked) {
            dp1 = max(save1 + world1[i], save2 - k + world1[i]);
            dp2 = max(save2 + world2[i], save1 - k + world2[i]);
        } else {
            dp1 = save1 + world1[i];
        }
    }

    cout << max(dp1, dp2) << endl;
    return 0;
}