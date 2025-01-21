#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

struct Vec2Int
{
    int x, y;
    Vec2Int() : x(0), y(0) {}
    Vec2Int(int x, int y) : x(x), y(y) {}

    void operator+=(const Vec2Int& v)
    {
        x += v.x;
        y += v.y;
    }
    
    Vec2Int operator-() const
    {
        return Vec2Int(-x, -y);
    }

    bool operator==(const Vec2Int& v) const
    {
        return x == v.x && y == v.y;
    }
};

struct Vec2IntHash
{
    size_t operator()(const Vec2Int& v) const
    {
        size_t h = 17;
        h = h * 31 + hash<int>()(v.x);
        h = h * 31 + hash<int>()(v.y);
        return h;
    }
};

unordered_map<Vec2Int, deque<int>, Vec2IntHash> walked;
Vec2Int dir[128];
string actions;

int main()
{
    dir['W'] = Vec2Int(0, 1);
    dir['S'] = Vec2Int(0, -1);
    dir['A'] = Vec2Int(-1, 0);
    dir['D'] = Vec2Int(1, 0);

    int n;
    Vec2Int currPos(0, 0), target;
    cin >> n >> target.x >> target.y >> actions;

    if (target == currPos)
    {
        long long ans = 1LL * n * (n + 1) / 2;
        cout << ans << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        currPos += dir[actions[i]];
        walked[currPos].push_back(i);
    }

    long long ans = 0;
    for (int i = 0; i < n; target += dir[actions[i++]])
    {
        auto it = walked.find(target);
        if (it == walked.end())
            continue;
        while (!it->second.empty() && it->second.front() < i)
            it->second.pop_front();
        if (it->second.empty())
            continue;
        ans += n - it->second.front();
        // cerr << it->second.front() << endl;
    }
    cout << ans;

    return 0;
}