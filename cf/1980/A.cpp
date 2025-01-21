#include <iostream>
#include <map>

using namespace std;

inline void solve()
{
    int n, m, ans = 0;
    cin >> n >> m;
    string s;
    cin >> s;
    map<char, int> cnts;
    cnts['A'] = 0;
    cnts['B'] = 0;
    cnts['C'] = 0;
    cnts['D'] = 0;
    cnts['E'] = 0;
    cnts['F'] = 0;
    cnts['G'] = 0;
    for (auto c : s)
        cnts[c]++;
    for (auto p : cnts)
        ans += max(0, m - p.second);
    cout << ans << '\n';
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