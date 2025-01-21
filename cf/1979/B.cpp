#include <iostream>

using namespace std;

inline void solve()
{
    int x, y;
    cin >> x >> y;
    int z = x ^ y;
    z = z & -z;
    cout << z << '\n';
}

int main()
{
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