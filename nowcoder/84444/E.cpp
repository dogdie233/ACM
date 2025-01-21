#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
typedef long long ll;

pair<int, ll> arr[100001];
ll presum[100001];
map<int, pair<ll, ll>> days;

ll query(int day)
{
    auto it = days.upper_bound(day);
    it--;
    return it->second.first + it->second.second * (day - it->first);
}

int main()
{
    int n, q;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> arr[i].second;
    for (int i = 1; i <= n; i++)
        cin >> arr[i].first;
    
    cin >> q;
    sort(arr + 1, arr + n + 1, [](pair<int, ll> a, pair<int, ll> b) { return a.first < b.first; });
    for (int i = 1; i <= n; i++)
        presum[i] = presum[i - 1] + arr[i].second;
    
    days[1] = {presum[n], presum[n]};
    int cursor = 1;
    while (cursor <= n)
    {
        int cursorQWQ = cursor;
        while (cursorQWQ <= n && arr[cursorQWQ + 1].first == arr[cursorQWQ].first)
            cursorQWQ++;
        
        int day = arr[cursorQWQ].first;
        ll blockSum = presum[n] - presum[cursorQWQ];
        auto prev = days.crbegin();
        days[day + 1] = { prev->second.first + prev->second.second * (day - prev->first) + blockSum, blockSum };
        cursor = cursorQWQ + 1;
    }


    while (q--)
    {
        int day;
        cin >> day;
        cout << query(day) << endl;
    }

    return 0;
}