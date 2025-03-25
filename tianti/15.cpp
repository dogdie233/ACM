#include <iostream>

using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int n;
    char ch;
    cin >> n >> ch;
    for (int i = 0; i < (n + 1) / 2; i++) {
        for (auto j = 0; j < n; j++) {
            cout << ch;
        }
        cout << '\n';
    }
    return 0;
}