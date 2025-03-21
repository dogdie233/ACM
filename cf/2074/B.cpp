#include <iostream>
#include <stdint.h>
#include <ranges>
#include <numeric>

typedef int64_t num_t;

num_t arr[200000];

using namespace std;

inline void solve() {
    int n;
    cin >> n;
    auto subarr = ranges::subrange(arr, arr + n);
    for (auto& x : subarr) {
        cin >> x;
    }
    auto sum = accumulate(subarr.begin(), subarr.end(), 0);
    cout << sum - n + 1 << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}