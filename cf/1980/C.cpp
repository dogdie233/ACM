#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll a[200000], b[200000], d[200000];

inline void solve()
{
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> d[i];
    
    // 找到d中最后一个元素在b中的位置并删除
    {
        ll lastD = d[--m];
        int idx = -1;
        do { idx = find(b + idx + 1, b + n, lastD) - b; }
        while (idx + 1 < n && b[idx] == a[idx]);
        if (idx == n)
            idx = find(b, b + n, lastD) - b;
        if (idx == n)
        {
            cout << "NO" << '\n';
            return;
        }
        a[idx] = a[n - 1];
        b[idx] = b[--n];
    }

    // 删除a和b中相同的元素
    {
        int i = 0;
        while (i < n)
        {
            if (a[i] == b[i])
            {
                a[i] = a[n - 1];
                b[i] = b[--n];
                continue;
            }
            i++;
        }
    }

    // 判断b是否为d的子集
    sort(b, b + n);
    sort(d, d + m);
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while (j < m && b[i] != d[j])
            j++;
        if (j == m)
        {
            cout << "NO" << '\n';
            return;
        }
        j++;
    }

    cout << "YES" << '\n';
}

int main()
{
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #endif
    int batch;
    cin >> batch;
    while (batch--)
        solve();
    return 0;
}