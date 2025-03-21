#include <iostream>
#include <ranges>
#include <cmath>

using namespace std;

int container[100000];

int main() {
    int n, ans = -1;
    cin >> n;
    auto arr = ranges::subrange(container, container + n);
    for (auto &x : arr) {
        cin >> x;
    }
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            ans = max(ans, arr[i] - (arr[i - 1] + arr[i + 1]) / 2);
        }
    }
    cout << ans;
}