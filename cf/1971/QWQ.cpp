#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;
typedef long long ll;
const int N = 200001;

struct Node
{
    vector<int> conns;
    vector<ll> lengths;
};
struct Leaf
{
    int layer;
    int parent;
    ll length;
};

Node mp[N];
Leaf tree[N];
unordered_map<ll, ll> cache;

int main()
{
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #endif

    int n, m;
    cin >> n >> m;

    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        mp[u].conns.push_back(v);
        mp[v].conns.push_back(u);
        mp[u].lengths.push_back(w);
        mp[v].lengths.push_back(w);
    }

    int root = 1;
    for (int i = 1; i <= n; i++)
        if (mp[i].conns.size() > mp[root].conns.size())
            root = i;

    auto build = [&] (auto &&self, int idx) -> void
    {
        for (int i = 0; i < mp[idx].conns.size(); i++)
        {
            int conn = mp[idx].conns[i];
            if (conn == tree[idx].parent)
                continue;
            tree[conn].length = mp[idx].lengths[i];
            tree[conn].parent = idx;
            tree[conn].layer = tree[idx].layer + 1;
            self(self, conn);
        }
    };
    build(build, root);

    auto dfs = [&] (auto &&self, int idxa, int idxb) -> ll
    {
        if (idxa == idxb)
            return 0;
        ll length = cache[((ll)idxa << 32) + idxb];
        if (length == 0)
        {
            length = self(self, tree[idxa].parent, tree[idxb].parent) + tree[idxa].length + tree[idxb].length;
            cache[((ll)idxa << 32) + idxb] = cache[((ll)idxb << 32) + idxa] = length;
        }
        return length;
    };

    auto bl = [&] (auto &&self, int u, int v) -> ll
    {
        ll length = cache[((ll)u << 32) + v];
        if (length == 0)
        {
            if (tree[u].layer != tree[v].layer)
            {
                length = self(self, tree[u].parent, v) + tree[u].length;
                cache[((ll)u << 32) + v] = cache[((ll)v << 32) + u] = length;
            }
            else
                length = dfs(dfs, u, v);
        }
        return length;
    };

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        if (tree[u].layer < tree[v].layer)
            swap(u, v);
        cout << bl(bl, u, v) << '\n';
    }

    return 0;
}