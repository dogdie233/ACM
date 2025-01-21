#include <iostream>

using namespace std;
using ll = long long;

#define YES cout << "Yes\n"
#define NO cout << "No\n"

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
        ll n, m, a, b;
        cin >> n >> m >> a >> b;
        if (n & m & 1)
        {
            NO;
            continue;
        }
        if (n < 2 || m < 2)
        {
            if (a || (n + m == 3))
                YES;
            else
                NO;
            continue;
        }
        if (b)
            YES;
        else
            NO;
    }
    return 0;
}