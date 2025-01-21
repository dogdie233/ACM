#include <iostream>

using namespace std;

int cache[1001];

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

inline void solve()
{
    int x, y = 0;
    cin >> x;
    if (cache[x] == 0)
    {
        int res = 0;
        while ((++y) < x)
        {
            int v = gcd(x, y) + y;
            if (v > res)
            {
                cache[x] = y;
                res = v;
            }
        }
    }
    cout << cache[x] << endl;
}

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #endif

    int batch;
    cin >> batch;
    while (batch--)
        solve();
    return 0;
}