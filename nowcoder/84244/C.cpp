#include <iostream>
#include <map>

using namespace std;

map<int, bool> goodCache;

inline constexpr int digitSum(int v)
{
    int sum = 0;
    while (v)
    {
        sum += v % 10;
        v /= 10;
    }
    return sum;
}

inline bool isGoodNum(int v)
{
    if (goodCache.find(v) != goodCache.end())
        return goodCache[v];
    int sum = digitSum(v);
    bool good = (sum % 2 == 0) && (sum < v ? isGoodNum(sum) : true);
    goodCache[v] = good;
    return good;
}

int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        ans += isGoodNum(i);
    cout << ans;
    return 0;
}