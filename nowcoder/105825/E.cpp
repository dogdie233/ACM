#include <bits/stdc++.h>

using namespace std;

struct LR {
    int l, r;
};

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int n;
    cin >> n;
    auto arr = vector<int>(n);
    auto minLR = vector<LR>(n, LR{-1, n});
    for (auto &num : arr) {
        cin >> num;
    }
    for (auto i = 0; i < n; i++) {
        for (auto l = i - 1; l >= 0; l--) {
            if (arr[l] == arr[i]) continue;
            if (gcd(arr[l], arr[i]) != 1) {
                minLR[i].l = l;
                break;
            }
        }
        for (auto r = i + 1; r < n; r++) {
            if (arr[r] == arr[i]) continue;
            if (gcd(arr[r], arr[i]) != 1) {
                minLR[i].r = r;
                break;
            }
        }
    }

    
    return 0;
}