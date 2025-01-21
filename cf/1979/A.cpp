#include <iostream>

using namespace std;

inline void solve()
{
    int n, num, k = INT_MAX;
    cin >> n >> num;
    while (--n)
    {
        int num2;
        cin >> num2;
        k = min(k, max(num, num2) - 1);
        num = num2;
    }
    cout << k << '\n';
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