#include <iostream>

using namespace std;

inline void solve()
{
    int n, m, ans = 0;
    string a, b;
    cin >> n >> m >> a >> b;
    for (int i = 0; i < b.length() && ans < a.length(); i++)
        ans += a[ans] == b[i];
    cout << ans << endl;
}

int main() {
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