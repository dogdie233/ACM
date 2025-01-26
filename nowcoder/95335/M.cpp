#include <bits/stdc++.h>

using namespace std;

int main()
{
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #endif
    string input;
    cin >> input;
    sort(input.begin(), input.end());
    cout << (input == "cdenoorw" ? "happy new year" : "I AK IOI");
    return 0;
}