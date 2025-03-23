#include <iostream>
#include <stdint.h>
#include <algorithm>
#include <ranges>
#include <numeric>

using namespace std;

int64_t container[200000];

inline void solve() {
    int32_t n, k;
    int64_t sum = 0, num;
    cin >> n >> k;
    auto arr = ranges::subrange(container, container + n);
    for (auto& num : arr) {
        cin >> num;
    }
    
    sort(arr.begin(), arr.end());
    auto zeroIt = lower_bound(arr.begin(), arr.end(), 0);
    arr = ranges::subrange(arr.begin() + min(static_cast<int32_t>(zeroIt - arr.begin()), k), arr.end());
    sum = accumulate(arr.begin(), arr.end(), sum);
    cout << sum << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--)
        solve();
}