#include <bits/stdc++.h>

using namespace std;

struct QwQ
{
    int value, left, right;

    QwQ() : value(0), left(0), right(0) {}
    QwQ(int value, int left, int right) : value(value), left(left), right(right) {}
};

int arr[100000];

int main()
{
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #endif
    int n;
    cin >> n;
    auto constraints = vector<QwQ>(n);
    for (int i = 0; i < n; i++)
    {
        constraints[i].value = i + 1;
        cin >> constraints[i].left >> constraints[i].right;
    }
    sort(constraints.begin(), constraints.end(), [](const QwQ &a, const QwQ &b) {
        return (a.right - a.left) < (b.right - b.left);
    });

    auto dfs = [&](auto dfs, int idx) -> bool
    {
        if (idx == constraints.size())
            return true;
        for (int pos = constraints[idx].left - 1; pos < constraints[idx].right; pos++)
        {
            if (arr[pos] != 0)
                continue;
            arr[pos] = constraints[idx].value;
            if (dfs(dfs, idx + 1))
                return true;
            arr[pos] = 0;
        }
        return false;
    };

    if (!dfs(dfs, 0))
        return cout << -1, 0;
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    return 0;
}