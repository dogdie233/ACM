#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    char one;
    int ans;
    vector<int> children;
};

Node graph[100001];

int main()
{
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> graph[i].one;
        graph[i].one -= '0';
    }

    for (int i = 1; i < n; i++)
    {
        int parent, child;
        cin >> parent >> child;
        graph[parent].children.push_back(child);
    }

    auto dfs = [&] (auto &&self, Node& node) -> int
    {
        for (int child : node.children)
            node.ans += self(self, graph[child]);
        return node.ans + node.one;
    };
    
    dfs(dfs, graph[1]);
    
    for (int i = 1; i <= n; i++)
        cout << graph[i].ans << '\n';
}