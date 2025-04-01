#include <iostream>
#include <string>

using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int sum = 1;
    string str;
    cin >> str;
    for (auto ch : str) {
        if (ch == '-') sum--;
        else if (ch == '*') sum *= 2;
        
        if (sum >= 2025) return cout << "YES" << endl, 0;
    }
    return cout << "NO" << endl, 0;
}