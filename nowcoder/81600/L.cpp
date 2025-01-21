#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
using ll = long long;

const ll MOD = 998244353;

ll nums[100];
vector<pair<int, ll>> flags;

int main()
{
    int batch;
    cin >> batch;
    while (batch--)
    {
        int n;
        cin >> n;
        ll ans = 1;

        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        for (int i = 0; i < n; i++)
        {
            ll sum = 0;
            for (int j = 0; j <= i; j++)
            {
                if (nums[j] <= nums[i])
                {
                    continue;
                    flags.push_back({j, nums[j]});
                    s
                }
            }
            
        }

        cout << ans << '\n';
    }
    return 0;
}