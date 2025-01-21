#include <iostream>
#include <string.h>

using namespace std;

char str[1001];

inline void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int td1 = a - c, td2 = a - d;
    int td3 = b - c, td4 = b - d;

    cout << ((((td1 ^ td2) >> 31) ^ ((td3 ^ td4) >> 31)) ? "YES" : "NO") << '\n';
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