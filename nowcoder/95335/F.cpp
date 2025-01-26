#include <bits/stdc++.h>

using namespace std;

int main()
{
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #endif
    
    int t, n, a, b, c, sum;
    cin >> t;
    while (t--)
    {
        cin >> n >> a >> b >> c;
        sum = a + b + c;
        cout << (sum % 2 == 0 && sum / 2 == n ? "Yes" : "No") << endl;
    }
}