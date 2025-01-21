#include <iostream>
#include <numeric>
#include <vector>
#include <unordered_set>

using namespace std;

inline void solve()
{
    int n, cnt;
    cin >> n;
    vector<int> s(n);
    for (int i = n - 1; i >= 0; i--)
        cin >> s[i];
    cnt = 0;

    unordered_set<int> flags(s.begin(), s.begin() + n);
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            int gcdv = gcd(s[i], s[j]);
            if (flags.find(gcdv) == flags.end())
            {
                cnt++;
                flags.insert(gcdv);
                s.push_back(gcdv);
                n++;
            }
        }
    }
    cout << ((cnt & 1) ? "dXqwq" : "Haitang") << '\n';
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