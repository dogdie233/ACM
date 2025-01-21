#include <iostream>
#include <algorithm>

using namespace std;

int arr[100];

inline void solve()
{
    int n, f, k, fav;
    cin >> n >> f >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    fav = arr[f - 1];
    sort(arr, arr + n, greater<int>());
    if (arr[k - 1] < fav)
        cout << "YES" << '\n';
    else if (arr[k - 1] > fav)
        cout << "NO" << '\n';
    else
    {
        if (k < n && arr[k] == fav)
            cout << "MAYBE" << '\n';
        else
            cout << "YES" << '\n';
    }
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