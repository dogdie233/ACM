#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<ll> a(100001);
vector<ll> b(100001);

inline void solve()
{
    ll n, k, q;
    cin >> n >> k >> q;

    for (int i = 1; i <= k; i++)
        cin >> a[i];
    for (int i = 1; i <= k; i++)
        cin >> b[i];
    
    while (q--)
    {
        ll p;
        cin >> p;
        auto it = lower_bound(a.begin(), a.begin() + k + 1, p);
        if (*it == p)
        {
            cout << b[it - a.begin()] << ' ';
            continue;
        }

        int idx = it - a.begin();
        long double time = ((long double)(p - a[idx - 1]) * (b[idx] - b[idx - 1]) / (a[idx] - a[idx - 1])) + b[idx - 1];
        cout << (ll)time << ' ';
    }
    cout << '\n';
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
        solve();

    return 0;
}