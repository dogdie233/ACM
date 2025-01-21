#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
using ll = long long;

ll arr[500000];

int main()
{
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #endif        
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> v;
        v.push_back(1);
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        if (n == 1)
        {
            cout << 0 << '\n';
            continue;
        }
        sort(arr, arr + n);
        ll ans = numeric_limits<ll>::max();
        for (int i = 1; i < n; i++)
            ans = min(ans, arr[i] - arr[i - 1]);

        cout << setprecision(1) << fixed;

        cout << ans << '\n';
    }
    return 0;
}