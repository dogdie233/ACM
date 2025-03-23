#include <iostream>
#include <string>

using namespace std;

inline void solve() {
    int n, ans1 = 0, ans2 = 0;
    cin >> n;
    string str;
    cin >> str;
    for (int i = 1; i < str.size(); i += 2) {
        ans1 += str[i - 1] != str[i];
    }
    for (int i = str.size() - 2; i >= 0; i -= 2) {
        ans2 += str[i] != str[i + 1];
    }
    cout << min(ans1, ans2) << '\n';
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}