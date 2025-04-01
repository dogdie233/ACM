#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int n;
    cin >> n;
    vector<int> dp(n + 1);  // idx0的val永远是0
    vector<int> nums(n + 1);
    for (auto i = 1; i <= n; i++) {
        for (auto j = 1; j <= i; j++) {
            cin >> nums[j];
        }
        for (auto j = i; j > 0; j--) {
            dp[j] = max(dp[j], dp[j - 1]) + nums[j];
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}