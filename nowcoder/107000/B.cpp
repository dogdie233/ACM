// Nowcoder Compiler: C++（clang++18）
#include <iostream>
#include <string>

using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int n, ans = 0;
    string str;
    cin >> n >> str;

    bool qaq = false;
    for (int i = 0; i < n; i++) {
        if (str[i] == '0') {
            qaq = false;
            continue;
        }
        if (str[i] == '1') {
            if (qaq) {
                ans++;
            }
            qaq = !qaq;
        }
    }
    cout << ans << endl;
    return 0;
}