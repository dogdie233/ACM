#include <iostream>

using namespace std;
using ll = long long;

const ll MOD = 2097152;
ll prefix[500001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int q, t, v, top = 1;
    cin >> q;
    while (q--)
    {
        cin >> t >> v;
        top -= t;
        prefix[top] = prefix[top - 1] + v;
        ll ans = 0;
        for (int i = 0; i < top; i++)
            ans ^= prefix[top] - prefix[i];
        top++;
        cout << (ans % MOD) << '\n';
    }
    return 0;
}