#include <iostream>
#include <stack>

using namespace std;

inline void solve() {
    int n;
    char ch;
    cin >> n;
    stack<char> stk;
    for (int i = 0; i < n; i++) {
        cin >> ch;
        if (!stk.empty() && stk.top() == ch)
            stk.pop();
        else
            stk.push(ch);
    }
    cout << (stk.size() / 2) << '\n';
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}