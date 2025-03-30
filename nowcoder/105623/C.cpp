#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>

using namespace std;

inline void solve() {
    int n, value, op = 0;
    cin >> n;
    vector<int32_t> isNegative(n, 0);
    for (auto &num : isNegative) {
        cin >> num;
    }
    string pattern;
    cin >> pattern;

    for (int i = 0; i < n; i++) {
        if (isNegative[i] == 0) {
            isNegative[i] = pattern[i] == '<' ? 1 : (pattern[i] == '>' ? 0 : isNegative[i - 1]);
            op++;
            continue;
        }
        isNegative[i] = isNegative[i] < 0;
    }

    for (int i = 0; i < n; i++) {
        if ((pattern[i] == '<' && isNegative[i])
            || (pattern[i] == '>' && !isNegative[i])
            || (pattern[i] == 'Z' && !(isNegative[i] ^ isNegative[i - 1]))) {
            continue;
        }
        op++;
        isNegative[i] = !isNegative[i];
    }
    
    cout << op << endl;
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