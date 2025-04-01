#include <iostream>
#include <stdint.h>

using namespace std;

inline void solve() {
    string n;
    cin >> n;
    
    int64_t maxSum = 0;
    for (int i = 1; i < n.length(); ++i) {
        string left = n.substr(0, i);
        string right = n.substr(i);
        
        int64_t sum = stoll(left) + stoll(right);
        maxSum = max(maxSum, sum);
    }
    
    cout << maxSum << endl;
}

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}