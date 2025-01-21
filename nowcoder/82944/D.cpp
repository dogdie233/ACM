#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node
{
    vector<int> conns;
};

int main()
{
    int n;
    cin >> n;
    vector<Node> nodes(n);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        nodes[a - 1].conns.push_back(b - 1);
        nodes[b - 1].conns.push_back(a - 1);
    }

    int cut = 0;
    auto dfs = [&](auto &&dfs, int cur, int par) -> int
    {
        int ret = 0;
        for (int conn : nodes[cur].conns)
        {
            if (conn == par)
                continue;
            if ((dfs(dfs, conn, cur) & 1) == 0)
                cut++;
            else
                ret++;
        }
        return ret + 1;
    };

    cout << (((dfs(dfs, 0, 0) & 1) == 0) ? cut : -1);
}