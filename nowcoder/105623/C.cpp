#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline void solve() {
    int n, value, op = 0;
    cin >> n;
    vector<uint8_t> isNegative(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> value;
        isNegative[i] = value < 0;
    }
    string pattern;
    cin >> pattern;

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