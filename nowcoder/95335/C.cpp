    #include <bits/stdc++.h>

using namespace std;

struct Node
{
    int cost;
    vector<shared_ptr<Node>> child;

    Node() : cost(0), child(26) {}

    void updateCost()
    {
        cost = 2;
        for (auto& c : child)
        {
            if (c != nullptr)
            {
                c->updateCost();
                cost += c->cost;
            }
        }
    }
};

void push(Node& parent, const char* pStr)
{
    if (*pStr == 0)
        return;

    auto index = *pStr - 'a';
    if (parent.child[index] == nullptr)
        parent.child[index] = make_shared<Node>();

    push(*parent.child[index], pStr + 1);
}

int main()
{
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#endif

    int n, m, longest = 0;
    string s;
    shared_ptr<Node> root = make_shared<Node>();
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        push(*root, s.c_str());
        longest = max(longest, (int)s.size());
    }

    root->updateCost();
    cout << root->cost - longest - 2 << endl;

    return 0;
}