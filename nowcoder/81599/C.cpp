#include <iostream>
#include <cstring>

using namespace std;

int arr[1000001];
bool walked[1000001];

int main()
{
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #endif
    int _, n;
    cin >> _;
    while (_--)
    {
        cin >> n;
        memset(walked, 0, n);
        for (int i = 1; i <= n; i++)
            cin >> arr[i];

        int fast = 0, slow = 0, sol = 0, ans = 0;
        while (sol < n && arr[sol + 1] == sol + 1)
            sol++;
        while (sol < n)
        {
            fast = slow = sol + 1;
            int num = 0;
            do
            {
                num++;
                fast = arr[arr[fast]];
                slow = arr[slow];
                walked[slow] = true;
            } while (fast != slow);
            num += 1;
            ans += num / 3 * 2 - 1 + (num % 3 > 0);
            while (sol < n && (arr[sol + 1] == sol + 1 || walked[sol + 1]))
                sol++;
        }
        
        cout << ((ans + 1) >> 1) << '\n';
    }

    return 0;
}