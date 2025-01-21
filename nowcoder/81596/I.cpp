#include <iostream>
#include <string>
#include <unordered_set>
#include <cstring>
#include <vector>
#include <unordered_map>

using namespace std;

struct Vec2
{
    int x, y;

    Vec2() : x(0), y(0) {}
    Vec2(int x, int y) : x(x), y(y) {}

    Vec2 operator+(const Vec2& v) const
    {
        return { x + v.x, y + v.y };
    }

    Vec2 operator-(const Vec2& v) const
    {
        return { x - v.x, y - v.y };
    }

    Vec2 operator-() const
    {
        return { -x, -y };
    }

    bool operator==(const Vec2& v) const
    {
        return x == v.x && y == v.y;
    }

    bool operator!=(const Vec2& v) const
    {
        return x != v.x || y != v.y;
    }

    static Vec2 up() { return { 0, -1 }; }
    static Vec2 down() { return { 0, 1 }; }
    static Vec2 left() { return { -1, 0 }; }
    static Vec2 right() { return { 1, 0 }; }

    int toId() const
    {
        return (x >> 31) | (y >> 30);
    }
};
struct Vec2Hash
{
    size_t operator()(const Vec2& v) const
    {
        return hash<int>()(v.x) ^ hash<int>()(v.y);
    }
};
struct History
{
    Vec2 pos;
    Vec2 dirFrom;

    History(const Vec2& pos, const Vec2& dirFrom) : pos(pos), dirFrom(dirFrom) {}

    bool operator==(const History& h) const
    {
        return pos == h.pos && dirFrom == h.dirFrom;
    }
};
struct HistoryHash
{
    size_t operator()(const History& h) const
    {
        return hash<int>()(h.pos.x) ^ hash<int>()(h.pos.y) ^ hash<int>()(h.dirFrom.x) ^ hash<int>()(h.dirFrom.y);
    }
};

int n, m;

bool isInside(const Vec2& pos)
{
    return pos.x >= 0 && pos.x < m && pos.y >= 0 && pos.y < n;
}

typedef void (*Action)(const Vec2 myPos, const Vec2 dirFrom);

Action mp[1000][1000];
Action mpActionTrans[128];
Vec2(*dirTrans[128])();
int cache[1000][1000][4];
unordered_set<History, HistoryHash> history;
unordered_map<Vec2, int, Vec2Hash> used;
vector<History> walked;

void go(const Vec2 fromPos, const Vec2 dirTo)
{
    Vec2 nextPos = fromPos + dirTo;
    Vec2 dirFrom = -dirTo;
    if (!isInside(nextPos))
    {
        for (int i = 0; i < walked.size(); i++)
        {
            cache[walked[i].pos.y][walked[i].pos.x][walked[i].dirFrom.toId()] = used.size();
            auto it = used.find(walked[i].pos);
            if (it != used.end())
            {
                if (it->second == 1)
                    used.erase(it);
				else
					it->second--;
            }
        }
        return;
    }
    if (history.find({ nextPos, dirFrom }) != history.end())
    {
        for (int i = 0; i < walked.size(); i++)
			cache[walked[i].pos.y][walked[i].pos.x][walked[i].dirFrom.toId()] = used.size();
        return;
    }
    history.insert({ nextPos, dirFrom });
    walked.push_back({ nextPos, dirFrom });
    mp[nextPos.y][nextPos.x](nextPos, dirFrom);
}

void a(const Vec2 myPos, const Vec2 dirFrom)
{
    if (dirFrom == Vec2::right() || dirFrom == Vec2::left())
        go(myPos, -dirFrom);
    else
    {
        if (used.find(myPos) == used.end())
            used[myPos] = 1;
        else
            used[myPos]++;
        go(myPos, dirFrom);
    }
}

void b(const Vec2 myPos, const Vec2 dirFrom)
{
    if (dirFrom == Vec2::up() || dirFrom == Vec2::down())
        go(myPos, -dirFrom);
    else
    {
        if (used.find(myPos) == used.end())
            used[myPos] = 1;
        else
            used[myPos]++;
        go(myPos, dirFrom);
    }
}

void c(const Vec2 myPos, const Vec2 dirFrom)
{
    if (used.find(myPos) == used.end())
        used[myPos] = 1;
    else
        used[myPos]++;
    go(myPos, Vec2(dirFrom.y, dirFrom.x));
}

void d(const Vec2 myPos, const Vec2 dirFrom)
{
    if (used.find(myPos) == used.end())
        used[myPos] = 1;
    else
        used[myPos]++;
    go(myPos, Vec2(-dirFrom.y, -dirFrom.x));
}

inline void buildTrans()
{
    mpActionTrans['-'] = a;
    mpActionTrans['|'] = b;
    mpActionTrans['/'] = c;
    mpActionTrans['\\'] = d;

    dirTrans['a'] = Vec2::up;
    dirTrans['b'] = Vec2::down;
    dirTrans['l'] = Vec2::left;
    dirTrans['r'] = Vec2::right;
}

int main()
{
    buildTrans();
    cin >> n >> m;

    while (cin.peek() <= '\n')
        cin.get();
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
            mp[y][x] = mpActionTrans[cin.get()];
        while (cin.get() != '\n');
    }
    memset(cache, 0xff, sizeof(cache));

    int q;
    string dirName;
    cin >> q;
    while (q--)
    {
        Vec2 pos, dir, nextPos;
        cin >> pos.y >> pos.x >> dirName;
        pos.y--, pos.x--;
        dir = dirTrans[dirName[0]]();
        nextPos = pos + dir;
        if (!isInside(nextPos))
        {
            cout << 0 << '\n';
            continue;
        }
        int ans = cache[nextPos.y][nextPos.x][(-dir).toId()];
        if (ans == -1)
        {
            history.clear();
            used.clear();
            walked.clear();
            go(pos, dir);
            ans = cache[nextPos.y][nextPos.x][(-dir).toId()];
        }
        cout << ans << '\n';
    }
    return 0;
}