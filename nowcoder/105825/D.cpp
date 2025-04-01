#include <iostream>
#include <algorithm> 
#include <ranges>

using namespace std;

typedef long long num_t;

num_t container[100000];
num_t diffs[100000];

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int n;
    num_t ans = 0;
    cin >> n;
    auto arr = ranges::subrange(container, container + n);
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        cin >> *it;
    }
    sort(arr.begin(), arr.end());
    if (all_of(arr.begin(), arr.end(), [&arr](num_t x) { return x == *arr.begin(); })) {  // 全是0
        return cout << 0 << endl, 0;
    }

    auto notZeroBegin = upper_bound(arr.begin(), arr.end(), 0);
    if (notZeroBegin == arr.end()) {  // 全是0
        return cout << 0 << endl, 0;
    } else if (notZeroBegin == arr.begin()) {  // 没有0
        return cout << -1 << endl, 0;
    }
    
    auto diff = ranges::subrange(diffs, diffs + n);
    diffs[0] = 0;
    for (auto i = 1; i < n; i++) {
        diffs[i] = arr[i] - arr[i - 1];
    }
    num_t goneSum = 0;

    notZeroBegin = notZeroBegin - arr.begin() + diff.begin();
    while (notZeroBegin != diff.end()) {
        auto mexValue = 1;
        if (arr[notZeroBegin - diff.begin()] - goneSum == 1) {
            mexValue = 2;
            for (auto it = notZeroBegin + 1; it < diff.end(); it++) {
                if (*it == 0) {
                    continue;
                } else if (*it != 1) {
                    break;
                }
                mexValue++;
            }
        }
        auto opCount = (num_t)0;
        
        if (mexValue == 1) {
            opCount = max(1ll, arr[notZeroBegin - diff.begin()] - goneSum - 1);
        } else {
            opCount = 1;
        }

        // cerr << mexValue << " " << opCount << endl;
        ans += opCount;
        auto reduceCount = opCount * mexValue;
        goneSum += reduceCount;
        notZeroBegin = upper_bound(arr.begin() + (notZeroBegin - diff.begin()), arr.end(), goneSum) - arr.begin() + diff.begin();
    }
    return cout << ans << endl, 0;
}