#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;
using ll = long long;

ll arr[100];

int main()
{
    ll n, m, ans;
    cin >> n >> m;
    ans = m;
    
    set<ll> nums, nums2;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        nums.insert(arr[i]);
    }

    int minn = 1;
    while (minn != *nums.cbegin())
    {
        auto left = nums.cbegin();
        minn = *left;
        nums2.clear();
        nums2.insert(*left);
        while (left != nums.cend())
        {
            for (auto num : nums)
            {
                if (num <= *left)
                    continue;
                nums2.insert(num % *left);
            }
            left++;
        }
        nums.swap(nums2);
        nums.erase(0);
    }

    cout << (m % *nums.cbegin());
    return 0;
}