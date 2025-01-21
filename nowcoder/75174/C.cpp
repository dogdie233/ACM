#include <iostream>
#include <algorithm>

using namespace std;
typedef long long i64;

i64 arr[100000];

int main()
{
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #endif
    int n;
    i64 ans = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
        ans += abs(arr[i] - (i + 1));

    cout << ans;
}