#include <iostream>
#include <algorithm>

#define ANS(msg) return cout << (msg) << '\n', void()

using namespace std;
 
inline void solve()
{
    int nums[3], k;
    cin >> nums[0] >> nums[1] >> nums[2] >> k;
    if (nums[0] == k || nums[1] == k || nums[2] == k)
        ANS(0);

    sort(nums, nums + 3);
    if (k < 0 || k > 2)
        ANS(-1);

    if (k == 0)
        ANS(1);
    
    if (k == 1)
        ANS((nums[0] != 0) + 1);
    
    if (k == 2)
    {
        if (nums[0] == 0 && (nums[1] == 1 || nums[2] == 1))
            ANS(1);
        else if (nums[0] > 2)
            ANS(3);
        else
            ANS(2);
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