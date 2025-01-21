#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int C = 3;
const int N = 500;

int cs[N * C];

inline void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < C; i++)
        for (int j = 0; j < n; j++)
            cin >> cs[j + N * i];

    // 剪枝，但是铸币cf的验题机不支持脚本验证答案，所以这坨没什么用
    int nn = n;
    for (int i = 0; i < nn; i++)
    {
        if (cs[i] + cs[i + N] == 0 || cs[i] + cs[i + N + N] == 0 || cs[i + N] + cs[i + N + N] == 0)
        {
            nn--;
            for (int j = 0; j < C; j++)
                cs[i + N * j] = cs[nn + N * j];
        }
    }

    int result[N + 1] = { 0 };
    auto dfs = [&] (auto &&self, int row) -> bool
    {
        if (row == nn)
            return true;
        
        for (int c = 0; c < C; c++)
        {
            int idx = row + c * N, absv = abs(cs[idx]);
            if (result[absv] == 0)
            {
                result[absv] = cs[idx] > 0 ? 1 : -1;
                if (self(self, row + 1))
                    return true;
                result[absv] = 0;
            }
            else if (result[absv] * cs[idx] > 0)
            {
                if (self(self, row + 1))
                    return true;
            }
        }
        return false;
    };

    cout << (dfs(dfs, 0) ? "YES" : "NO") << '\n';
    for (int i = 1; i <= n; i++)
        cout << result[i] << ' ';
    cout << '\n';
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