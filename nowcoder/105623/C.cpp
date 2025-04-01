#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>

using namespace std;

inline void solve() {
    int n, value, op = 0;
    cin >> n;
    vector<int32_t> nums(n, 0);
    for (auto &num : nums) {
        cin >> num;
    }
    string pattern;
    cin >> pattern;

    for (int i = 0; i < n; i++) {
        if (pattern[i] == '<') {
            if (nums[i] < 0) {
                continue;
            }
            nums[i] = -1;
        } else if (pattern[i] == '>') {
            if (nums[i] > 0) {
                continue;
            }
            nums[i] = 1;
        } else {
            if (nums[i] != 0 && !((nums[i] < 0) ^ (nums[i - 1] < 0))) {
                continue;
            }
            nums[i] = nums[i - 1];
        }
        op++;
    }
    
    cout << op << endl;
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