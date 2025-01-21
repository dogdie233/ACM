#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        bool ok = true;
        while (n--)
        {
            cin >> x;
            ok = ok && (x != 1);
        }
        cout << (ok ? "1000000007" : "-1") << endl;
    }
    return 0;
}