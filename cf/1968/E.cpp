#include <iostream>
#include <ranges>

using namespace std;

inline void solve()
{
    int n; cin >> n;
    cout << "1 1\n1 2\n";
    for (int i = 3; i <= n; i++)
        cout << i << ' ' << i << '\n';
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