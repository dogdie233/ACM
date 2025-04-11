// Nowcoder Compiler: C++（clang++18）
#include <iostream>
#include <stdint.h>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int64_t n, k, ans = 0, sum = 0;
    cin >> n >> k;
    auto nums = vector<int64_t>(n);
    for (auto& num : nums) {
        cin >> num;
    }
    auto buffer = vector<int64_t>(n + 1);
    auto leftBest = vector<int64_t>(n + 1);
    buffer[0] = leftBest[0] = 0ll;
    for (auto i = 1; i <= n; i++) {
        buffer[i] = buffer[i - 1] + nums[i - 1];
        leftBest[i] = max(leftBest[i - 1], buffer[i]);
    }
    auto rightBest = vector<int64_t>(n + 1);
    buffer[0] = rightBest[0] = 0ll;
    for (auto i = 1; i <= n; i++) {
        buffer[i] = buffer[i - 1] + nums[n - i];
        rightBest[i] = max(rightBest[i - 1], buffer[i]);
    }

    int64_t act = min(n, static_cast<decltype(act)>((-1 + std::sqrt(1 + 8 * k)) / 2) + 2);
    for (int i = 0; i <= act; i++) {
        sum = leftBest[i] + rightBest[act - i];
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}