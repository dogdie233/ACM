#include <iostream>
#include <cstring>
#include <limits>

using namespace std;

int mp[500][500], n;
bool vis[500][500];

void dfs(const int x, const int y, const int maxx)
{
    static pair<int, int> dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    if (mp[y][x] > maxx)
        return;
    vis[y][x] = true;
    for (auto [dx, dy] : dir)
    {
        dx += x, dy += y;
        if (dx >= 0 && dx < n && dy >= 0 && dy < n && !vis[dy][dx])
            dfs(dx, dy, maxx);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mp[i][j];
    int l = mp[n - 1][n - 1], r = 1e9, ans = r;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        memset(vis, 0, sizeof(vis));
        dfs(0, 0, mid);
        if (vis[n - 1][n - 1])
            r = mid - 1, ans = mid;
        else
            l = mid + 1;
    }
    cout << ans;
    return 0;
}