#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

inline void solve() {
    int n;
    cin >> n;
    auto nums = vector<int64_t>(n);
    auto dp = vector<int64_t>(n);

    for (auto& num : nums) {
        cin >> num;
    }
    if (n > 0) dp[0] = nums[0];
    if (n > 1) dp[1] = max(nums[1] + nums[0], 0ll);
    if (n > 2) dp[2] = max(nums[0] + nums[1] + nums[2], max(nums[0], 0ll));
    for (int i = 3; i < n; i++) {
        dp[i] = dp[i - 1] + nums[i];
        dp[i] = max(dp[i], max(dp[i - 2], dp[i - 3]));
    }

    cout << dp[n - 1] << endl;
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