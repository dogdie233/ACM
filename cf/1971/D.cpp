#include <iostream>
#include <string.h>

using namespace std;

char str[501];

inline void solve()
{
    cin >> str;
    int len = strlen(str), ans = 1;
    for (int i = 1; i < len; i++)
        ans += abs(str[i] - str[i - 1]);
    for (int i = 1; i < len; i++)
    {
        if (str[i] == '1' && str[i - 1] == '0')
        {
            ans -= 1;
            break;
        }
    }
    cout << ans << '\n';
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