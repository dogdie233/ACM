#include <iostream>
#include <stdint.h>
#include <ranges>
#include <algorithm>
#include <vector>
#include <set>
#include <numeric>

using namespace std;

int container[100];

inline void solve() {
    int n;
    cin >> n;
    auto arr = ranges::subrange(container, container + n);
    for (auto& num : arr) {
        cin >> num;
    }
    sort(arr.begin(), arr.end());

    uint64_t ans = numeric_limits<uint64_t>::max();
    set<uint64_t> possibles;
    vector<uint64_t> toInsert;
    possibles.insert(0);
    for (auto num : arr) {
        toInsert.clear();
        for (auto possible : possibles) {
            if (possible > num) {
                ans = min(ans, possible + num);
            }
            toInsert.push_back(possible + num);
        }

        for (auto num : toInsert) {
            possibles.insert(num);
        }
    }

    cout << static_cast<int64_t>(ans) << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}