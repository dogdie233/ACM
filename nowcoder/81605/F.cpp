#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int n;

struct Point
{
    int x, y;
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}

    operator size_t() const  // ToIndex
    {
        return y * n + x;
    }

    Point operator+(const Point &other) const
    {
        return Point(x + other.x, y + other.y);
    }

    Point operator-(const Point &other) const
    {
        return Point(x - other.x, y - other.y);
    }
};

bool flags[1001 * 1001];
vector<Point> insertedPoints;

inline bool IsPositionValid(const Point& point)
{
    return point.x > 0 && point.x <= n && point.y > 0 && point.y <= n;
}

inline void SmallistDiffPoint(Point& diff)
{
    int gcdValue = gcd(abs(diff.x), abs(diff.y));
    diff.x /= gcdValue;
    diff.y /= gcdValue;
}

int main()
{
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #endif
    cin >> n;
    int nn = n * n;
    for (int i = 0; i < nn; i++)
    {
        Point point;
        cin >> point.x >> point.y;

        if (flags[point])
        {
            cout << '0';
            continue;
        }

        for (auto otherPoint : insertedPoints)
        {
            Point diff = point - otherPoint;
            SmallistDiffPoint(diff);
            Point mkPoint = point + diff;
            while (IsPositionValid(mkPoint))
            {
                flags[mkPoint] = true;
                mkPoint = mkPoint + diff;
            }
            mkPoint = point - diff;
            while (IsPositionValid(mkPoint))
            {
                flags[mkPoint] = true;
                mkPoint = mkPoint - diff;
            }
        }

        flags[point] = true;
        insertedPoints.push_back(point);
        cout << '1';
    }
    return 0;
}