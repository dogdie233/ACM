#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stdint.h>

using namespace std;

int main() {
    int n, k;
    uint64_t ans = 0;
    string str;
    cin >> n >> k >> str;
    auto prefixSum = vector<uint64_t>(n);
    for (auto i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + abs(str[i] - str[i - 1]);
        if (i - k + 1 >= 0)
            ans += prefixSum[i] - prefixSum[i - k + 1];
    }
    return cout << ans, 0;
}