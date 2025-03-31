#include <iostream>
#include <stdint.h>
#include <limits>
#include <bit>
#include <vector>
#include <algorithm>

typedef uint32_t num_t;

using namespace std;

constexpr inline num_t lowbit(num_t x) {
    return x & -x;
}

inline void solve() {
    int n;
    num_t x, y, bitlen = numeric_limits<num_t>::digits;
    vector<num_t> nums;
    cin >> n >> x >> y;
    if (n == 1 && x != y) {
        cout << "NO" << endl;
        return;
    }
    for (num_t i = 0; i < bitlen - 1; i++) {
        num_t mask = (1 << i);
        if ((x & mask) < (y & mask)) {
            cout << "NO" << endl;
            return;
        }
    }

    nums.push_back(x);
    nums.push_back(x ^ y);
    if (nums[1] == 0) {
        nums.push_back(nums[1] = nums[0]);
    }

    if (nums.size() > n) {
        cout << "NO" << endl;
        return;
    }
    
    if ((n - nums.size()) % 2 == 1) {
        auto it = find_if(nums.begin(), nums.end(), [](num_t num) { return popcount(num) > 1; });
        if (it == nums.end()) {
            cout << "NO" << endl;
            return;
        }
        auto lb = lowbit(*it);
        *it = *it ^ lb;
        nums.push_back(lb);
    }

    cout << "YES\n";
    for (const auto& num : nums) {
        cout << num << " ";
    }
    for (int i = nums.size(); i < n; i++) {
        cout << nums[0] << " ";
    }
    cout << '\n';
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