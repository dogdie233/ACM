#include <iostream>

using namespace std;
using ll = long long;

bool check(ll a1, ll k, ll m, ll h)
{
    ll sum = a1, term = a1;
    while (sum < h && term >= m)
    {
        ll append = term / m * k;
        sum += append;
        term = term % m + append;
    }
    return sum >= h;
}

int main()
{
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #endif
    int batch;
    cin >> batch;
    while (batch--)
    {
        ll m, k, h;
        cin >> m >> k >> h;
        ll l = 0, r = h;
        if (k == m)
        {
            cout << min(k, h) << '\n';
            continue;
        }
        while (l + 1 < r)
        {
            ll mid = (l + r) / 2;
            if (check(mid, k, m, h))
                r = mid;
            else
                l = mid;
        }
        cout << r << '\n';
    }
    return 0;
}