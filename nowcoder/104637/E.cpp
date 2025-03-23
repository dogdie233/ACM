#include <iostream>
#include <stdint.h>
#include <ranges>
#include <algorithm>
#include <vector>

using namespace std;

int container[100];

int owo(vector<int>& arr, int longest) {
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(longest + 1, INT_MAX));
    
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= longest; j++) {
            if(dp[i - 1][j] != INT_MAX) {
                dp[i][j] = dp[i - 1][j];
            }
            
            if(arr[i - 1] >= j) {
                dp[i][j] = min(dp[i][j], arr[i - 1]);
            } else if(dp[i - 1][j - arr[i - 1]] != INT_MAX) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - arr[i - 1]] + arr[i - 1]);
            }
        }
    }
    
    int result = INT_MAX;
    for(int i = 1; i <= n; i++) {
        if(dp[i][longest] != INT_MAX) {
            result = min(result, dp[i][longest]);
        }
    }
    
    return result;
}

inline void solve() {
    int n, myLongestIndex = -1;
    int64_t prefixSum = 0;
    cin >> n;
    auto arr = ranges::subrange(container, container + n);
    for (auto& num : arr) {
        cin >> num;
    }
    sort(arr.begin(), arr.end());

    for (auto i = 0; i < n; i++) {
        if (prefixSum > arr[i]) {
            myLongestIndex = i;
            break;
        }
        prefixSum += arr[i];
    }
    if (myLongestIndex == -1) {
        cout << "-1\n";
        return;
    }

    auto qwq = vector<int>(myLongestIndex);
    for (auto i = 0; i < myLongestIndex; i++) {
        qwq[i] = arr[i];
    }
    auto ans = owo(qwq, arr[myLongestIndex]) + arr[myLongestIndex];
    cout << ans << '\n';
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}