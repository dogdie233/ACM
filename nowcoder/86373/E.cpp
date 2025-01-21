#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct node
{
    int score, belong;
};

multiset<int> q;
int mapCnt = 1;
node arra[100001], mapper[100001];
bool added[100001];

node& findRoot(int index)
{
    node* result = mapper + index;
    while (result - mapper != result->belong)
        result = mapper + result->belong;
    return *result;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> arra[i].score;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        if (arra[a].belong == arra[b].belong && arra[a].belong == 0)
        {
            arra[a].belong = arra[b].belong = mapper[mapCnt].belong = mapCnt;
            mapper[mapCnt].score = max(arra[a].score, arra[b].score);
            mapCnt++;
        }
        else if (arra[a].belong == 0)
        {
            auto& root = findRoot(arra[b].belong);
            arra[a].belong = root.belong;
            root.score = max(root.score, arra[a].score);
        }
        else if (arra[b].belong == 0)
        {
            auto& root = findRoot(arra[a].belong);
            arra[b].belong = root.belong;
            root.score = max(root.score, arra[b].score);
        }
        else
        {
            auto& rootA = findRoot(arra[a].belong);
            auto& rootB = findRoot(arra[b].belong);

            rootB.belong = rootA.belong;
            rootA.score = max(rootA.score, rootB.score);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (arra[i].belong == 0)
            q.insert(arra[i].score);
        else if (mapper[arra[i].belong].belong == arra[i].belong && !added[arra[i].belong])
        {
            q.insert(mapper[arra[i].belong].score);
            added[arra[i].belong] = true;
        }
    }

    long long ans = 0;
    while (q.size() > 1)
    {
        q.erase(q.cbegin());
        auto it = q.cbegin();
        int score2 = *it;
        q.erase(it);

        ans += score2;
        q.insert(score2);
    }

    cout << ans;
    return 0;
}