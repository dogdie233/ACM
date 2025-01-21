#include <iostream>
#include <string.h>

using namespace std;

char str[1001];

inline void solve()
{
    cin >> str;
    int len = strlen(str);

    bool pass = false;
    for (int i = 1; i < len; i++)
    {
        if (str[i] == str[i - 1])
            continue;
        pass = true;
        swap(str[i], str[i - 1]);
        break;
    }
    if (!pass)
    {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n' << str << '\n';
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