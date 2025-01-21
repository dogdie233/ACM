#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int arr[200000], buf[200000];

inline void solve()
{
    int n;
    map<int, vector<int>> group;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        group[arr[i] >> 2].push_back(i);
    }

    for (auto p : group)
    {
        vector<int> &idxs = p.second;
        for (int i = 0; i < idxs.size(); i++)
            buf[i] = arr[idxs[i]];
        sort(buf, buf + idxs.size());
        for (int i = 0; i < idxs.size(); i++)
            arr[idxs[i]] = buf[i];
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}

int main()
{
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #endif

    int batch;
    cin >> batch;
    while (batch--)
        solve();

    return 0;
}