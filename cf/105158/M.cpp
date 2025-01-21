#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int N = 2e5 + 3;
ll n, ans;
void solve()
{
    cin >> n;
    ans = 0;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    ll l = 0, r = 1e9;
    auto check = [&](ll k) -> bool
    {
        ll up = 1e18, down = -1e18;
        
        for (int i = 0; i < n; i++)
        {
            up = min(up, b[i] * k + a[i]);
            down = max(down, -b[i] * k + a[i]);
        }
        if (up < down)
            return false;
        return true;
    };
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}