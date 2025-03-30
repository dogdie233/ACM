#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

inline void solve() {
    int n;
    cin >> n;
    auto nums = vector<int64_t>(n);
    auto isDeleted = vector<bool>(n);

    for (auto& num : nums) {
        cin >> num;
    }

    for (int i = 1; i < n; i++) {
        if (nums[i] < 0 && isDeleted[i - 1]) {
            isDeleted[i] = true;
        } else {
            if (nums[i - 1] + nums[i] < 0) {
                isDeleted[i] = true;
                isDeleted[i - 1] = true;
            } else {
                continue;
            }
        }
    }
    int64_t sum = 0;
    for (int i = 0; i < n; i++) {
        if (!isDeleted[i]) {
            sum += nums[i];
        }
    }
    cout << sum << endl;
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