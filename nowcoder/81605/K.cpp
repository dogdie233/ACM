#include <bits/stdc++.h>

using namespace std;

int arr[100000], posAnsArr[100001], negAnsArr[100001];

inline void solve()
{
    int n;
    cin >> n;
    int zeroCnt = 0;
    int *negArr = arr, *posArr = arr, negCnt = 0, posCnt = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(!arr[i])
            zeroCnt++;
        else if (arr[i] < 0)
            negCnt++;
        else
            posCnt++;
    }
    posArr = arr + negCnt + zeroCnt;
    
    // 跑负数
    {
        int right = negCnt - 1;
        for (int left = 0; left < negCnt; left++)
        {
            right = max(right, left);
            while (-negArr[right] <= left && right >= left)
                right--;
            negAnsArr[left] = negCnt - right - 1;
        }
        negAnsArr[negCnt] = 0;
    }

    // 跑正数
    {
        int left = 0;
        for (int cost = 0; cost < posCnt; cost++)
        {
            left = min(left, posCnt - cost - 1);
            while (posArr[left] <= cost && left < posCnt - cost)
                left++;
            posAnsArr[cost] = left;
        }
        posAnsArr[posCnt] = 0;
    }

    int ans = zeroCnt;
    for (int negCost = 0; negCost < negCnt; negCost++)
    {
        int negAns = negAnsArr[negCost];
        int posAns = negCost <= posCnt ? posAnsArr[posCnt - negCost] : 0;
        ans = max(ans, negAns + posAns + zeroCnt);
    }
    for (int posCost = 0; posCost < posCnt; posCost++)
    {
        int posAns = posAnsArr[posCost];
        int negAns = posCost <= negCnt ? negAnsArr[negCnt - posCost] : 0;
        ans = max(ans, negAns + posAns + zeroCnt);
    }

    cout << ans << '\n';
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