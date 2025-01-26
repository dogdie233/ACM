#include <bits/stdc++.h>

using namespace std;

int main()
{
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #endif

    int64_t count;
    cin >> count;
    cout << (count % 2 ? "Yes" : "No") << endl;
    return 0;
}