#include <bits/stdc++.h>

using namespace std;

map<int, vector<int>> tree;

int dfs(int from, const map<int, vector<int>>::const_iterator &it)
{
    if (it->second.size() == 1)
        return it->first;
    if (it->second.size() > 2)
        return -1;
    return dfs(it->first, tree.find(it->second[0] == from ? it->second[1] : it->second[0]));
}

int main()
{
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int src, dst;
    auto it = tree.cbegin();
    if (it->second.size() == 1)
    {
        src = it->first;
        dst = dfs(src, tree.find(it->second[0]));
    }
    else
    {
        src = dfs(it->first, tree.find(it->second[0]));
        dst = dfs(it->first, tree.find(it->second[1]));
    }

    if (src == -1 || dst == -1)
        cout << "-1" << endl;
    else
        cout << src << ' ' << dst << endl;

    return 0;
}