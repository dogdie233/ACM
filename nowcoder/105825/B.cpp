#include <iostream>
#include <string>

using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int n, diffCount = 0;
    string str;
    cin >> n >> str;
    for (auto i = 1; i < n; i++) {
        diffCount += (str[i] != str[i - 1]);
    }
    return cout << (diffCount < 2 ? "YES" : "NO") << endl, 0;
}