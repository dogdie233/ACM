#include <bits/stdc++.h>

using namespace std;

using ll = long long int;

int main()
{
    int n;
    ll cnt, sum;
    cin >> n;
    auto arr = vector<int>(n);
    for (auto &x : arr)
        cin >> x;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        sum += (i + 1) - arr[i];
        cnt += max((i + 1) - arr[i], 0);
    }

    cout << (sum == 0 ? cnt : -1) << endl;
    return 0;
}