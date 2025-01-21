#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int dc(ll x)
{
    ll res = 0;
    while (x)
    {
        x /= 10;
        res++;
    }
    return res;
}
void solve()
{
    ll n, d, digit, sum = 0;
    string s;
    cin >> n >> d;
    digit = dc(n);
    for (int i = 1; i <= 9; i++)
        s.push_back(i + '0');
    s.push_back('0' + d);
    for (int i = 0;; i++)
    {
        
    }
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