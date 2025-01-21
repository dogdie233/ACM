#include <bits/stdc++.h>

using namespace std;

int main()
{
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #endif

    int n;
    cin >> n;
    auto arr = vector<int>(n);
    for (auto &x : arr)
        cin >> x;
    
    auto minIt = min_element(arr.begin(), arr.end());
    auto maxIt = max_element(arr.begin(), arr.end());

    *minIt *= 2;
    int left = minIt - arr.begin();
    int right = left + 1;
    if (*minIt > *maxIt)
        maxIt = minIt;
    minIt = min_element(arr.begin(), arr.end());
    auto ans = *maxIt - *minIt;

    while (true)
    {
        auto pos = minIt - arr.begin();
        if (pos < left)
        {
            for (int i = pos; i < left; i++)
                arr[i] *= 2;
            left = pos;
        }
        else if (pos >= right)
        {
            for (int i = right; i <= pos; i++)
                arr[i] *= 2;
            right = pos + 1;
        }
        else
            break;
        
        minIt = min_element(arr.begin(), arr.end());
        maxIt = max_element(arr.begin(), arr.end());
        auto newAns = *maxIt - *minIt;
        if (newAns > ans)
            break;
        ans = newAns;
    }

    cout << ans << endl;
}