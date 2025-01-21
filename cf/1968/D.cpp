#include <iostream>
#include <ranges>
#include <string.h>
#include <algorithm>

using namespace std;
typedef long long ll;
const int N = 2e5 + 1;
int p[N]; int a[N];
bool walked[N];

inline void solve()
{
    int n, k, pb, ps;
    cin >> n >> k >> pb >> ps;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    auto dfs = [&] (auto &&self, int pos, ll k) -> ll
    {
        if (k == 0) return 0;
        if (walked[pos]) return k * a[pos];
        walked[pos] = true;
        return max(self(self, p[pos], k - 1) + a[pos], k * a[pos]);
    };
    auto run = [&] (int pos) -> ll
    {
        memset(walked + 1, 0, n);
        return dfs(dfs, pos, k);
    };
    ll delta = run(pb) - run(ps);
    if (delta == 0) cout << "Draw" << endl;
    else if (delta > 0) cout << "Bodya" << endl;
    else cout << "Sasha" << endl;
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