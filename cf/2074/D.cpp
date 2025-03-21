#include <iostream>
#include <map>
#include <ranges>
#include <cmath>

using namespace std;

int xContainer[200000];
double rContainer[200000];
map<int, int> heights;

inline void solve() {
    int n, m;
    cin >> n >> m;
    heights.clear();
    auto arrX = ranges::subrange(xContainer, xContainer + n);
    auto arrR = ranges::subrange(rContainer, rContainer + n);
    for (auto &x : arrX) {
        cin >> x;
    }
    for (auto &r : arrR) {
        cin >> r;
    }
    for (auto i = 0; i < n; i++) {
        for (auto delta = 0; delta <= rContainer[i]; delta++) {
            auto height = (int)sqrt(pow(rContainer[i], 2) - pow(delta, 2));
            heights[arrX[i] + delta] = max(heights[arrX[i] + delta], height);
            heights[arrX[i] - delta] = max(heights[arrX[i] - delta], height);
        }
    }
    int64_t ans = 0;
    for (auto [x, height] : heights) {
        ans += height * 2 + 1;
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}