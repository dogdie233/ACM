#include <iostream>
#include <algorithm> 
#include <ranges>

using namespace std;

typedef long long num_t;

template <typename _ForwardIterator>
num_t mex(_ForwardIterator begin, _ForwardIterator end, num_t m = 0) {
    for (auto it = begin; it != end; ++it) {
        if (*it < m) {
            continue;
        } else if (*it > m) {
            return m;
        }
        m++;
    }
    return m;
}

num_t container[100000];

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
    auto notZeroBegin = upper_bound(arr.begin(), arr.end(), 0);
    if (notZeroBegin == arr.end()) {
        return cout << 0 << endl, 0;
    } else if (notZeroBegin == arr.begin()) {
        return cout << -1 << endl, 0;
    }
    
    while (notZeroBegin != arr.end()) {
        auto mexValue = mex(notZeroBegin, arr.end(), 1);
        auto divCount = (num_t)0;
        
        if (mexValue == 1) {
            if (*notZeroBegin == 1) {
                divCount = 1;
            } else {
                divCount = *notZeroBegin - 1;
            }
        } else {
            divCount = 1;
        }

        ans += divCount;
        auto reduceCount = divCount * mexValue;
        for (auto it = notZeroBegin; it != arr.end(); ++it) {
            *it = max(0ll, *it - reduceCount);
        }
        notZeroBegin = upper_bound(notZeroBegin, arr.end(), 0);
    }
    cout << ans;
    return 0;
}