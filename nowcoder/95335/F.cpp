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

        int S = a + b + c - n;
        if (S < 0) {
            cout << "No" << endl;
            continue;
        }

        bool possible = false;
        for (int x1 = 0; x1 <= min({a, c, S}); x1++)
        {
            for (int x3 = 0; x3 <= min(a - x1, b); x3++)
            {
                int x5 = S - x1 - x3;
                if (x5 < 0 || x5 > c - x1 || x5 > b - x3)
                    continue;
                if (x1 + x3 <= a && x3 + x5 <= b && x1 + x5 <= c)
                {
                    possible = true;
                    break;
                }
            }
            if (possible)
                break;
        }
        cout << (possible ? "Yes" : "No") << endl;
    }
}