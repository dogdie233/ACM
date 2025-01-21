#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Team
{
    int id;
    int solved;
    int penalty;

    static bool cmp(const Team &a, const Team &b)
    {
        if (a.solved != b.solved)
            return a.solved > b.solved;
        return a.penalty < b.penalty;
    }
};

unordered_map<string, int> nameMap;
int n, m;
Team cpt1[100000], cpt2[100000];
bool tpi1[200000], tpi2[200000];

inline int getId(const string& name)
{
    if (nameMap.find(name) == nameMap.end())
        return nameMap[name] = nameMap.size();
    return nameMap[name];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string name;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        cin >> cpt1[i].solved >> cpt1[i].penalty;
        cpt1[i].id = getId(name);
        tpi1[cpt1[i].id] = true;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> name;
        cin >> cpt2[i].solved >> cpt2[i].penalty;
        cpt2[i].id = getId(name);
        tpi2[cpt2[i].id] = true;
    }
    sort(cpt1, cpt1 + n, Team::cmp);
    sort(cpt2, cpt2 + m, Team::cmp);
    
    int best = 0x7fffffff;
    int myId = getId("lzr010506");
    
    int rank = 1;
    for (int i = 0; i < n; i++)
    {
        if (cpt1[i].id == myId)
        {
            best = min(best, rank);
            break;
        }
        if (!tpi2[cpt1[i].id])
            rank++;
    }

    rank = 1;
    for (int i = 0; i < m; i++)
    {
        if (cpt2[i].id == myId)
        {
            best = min(best, rank);
            break;
        }
        if (!tpi1[cpt2[i].id])
            rank++;
    }

    cout << best;

    return 0;
}