#include <iostream>
#include <algorithm>
#include <ranges>
#include <vector>
#include <map>

#define YES return cout << "YES\n", void()
#define NO return cout << "NO\n", void()

using namespace std;

int a[200000], b[200000];
int buf[200000];

inline void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n * m; i++)
        cin >> a[i];
    for (int i = 0; i < n * m; i++)
        cin >> b[i];
    
    map<int, vector<int>> mp;
    for (int l = 0; l < n; l++)
    {
        auto vec = vector<int>(b + l * m, b + (l + 1) * m);
        sort(vec.begin(), vec.end());
        mp[vec[0]] = vec;
    }
    for (int l = 0; l < n; l++)
    {
        memcpy(buf, a + l * m, sizeof(int) * m);
        sort(buf, buf + m);
        auto it = mp.find(buf[0]);
        if (it == mp.end())
            NO;
        
        for (int i = 0; i < m; i++)
            if (it->second[i] != buf[i])
                NO;
    }

    mp.clear();
    for (int c = 0; c < m; c++)
    {
        auto vec = vector<int>(n);
        for (int l = 0; l < n; l++)
            vec[l] = b[l * m + c];
        sort(vec.begin(), vec.end());
        mp[vec[0]] = vec;
    }
    for (int c = 0; c < m; c++)
    {
        for (int l = 0; l < n; l++)
            buf[l] = a[l * m + c];
        sort(buf, buf + n);
        auto it = mp.find(buf[0]);
        if (it == mp.end())
            NO;
        
        for (int i = 0; i < n; i++)
            if (it->second[i] != buf[i])
                NO;
    }
    YES;
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