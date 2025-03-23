#include <iostream>
#include <stdint.h>
#include <ranges>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int container[100];

inline void solve() {
    int n;
    int64_t prefixSum = 0;
    cin >> n;
    auto arr = ranges::subrange(container, container + n);
    for (auto& num : arr) {
        cin >> num;
    }
    sort(arr.begin(), arr.end());

    set<int64_t> possibles;
    vector<int64_t> toInsert;
    possibles.insert(0);
    for (auto num : arr) {
        toInsert.clear();
        for (auto possible : possibles) {
            if (possible > num) {
                cout << (possible + num) << '\n';
                return;
            }
            toInsert.push_back(possible + num);
        }

        for (auto num : toInsert) {
            possibles.insert(num);
        }
    }

    cout << "-1\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}