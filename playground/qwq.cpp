#include <iostream>
#include <numeric>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n, num, ans = 0;
    cin >> n;
    map<int, int> dp;
    for (auto i = 0; i < n; i++) {
        cin >> num;

        // auto it = lower_bound(dp.begin(), dp.end(), num);
        auto it = lower_bound(dp.begin(), dp.end(), num, [](const auto& lhs, const auto& b) {
            return lhs.first < b;
        });
        if (it == dp.end()) {
            dp[num] = ++ans;
            continue;
        }

        if (it == dp.begin()) {
            dp[num] = 1;
            continue;
        }

        ans = max(ans, dp[num] = dp[prev(it)->second] + 1);
    }
    cout << ans;

    return 0;
}