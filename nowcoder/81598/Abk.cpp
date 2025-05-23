#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int arr[500000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll n, l, r;
    cin >> n >> l >> r;
    if (r == n)
    {
        cout << "Yes";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i] = (arr[i] - 1) / 2;
    }
    sort(arr, arr + n);
    int round = ((n - r) + (r - l - 1)) / (r - l);
    priority_queue<ll, vector<ll>, greater<ll>> p(arr + n - l, arr + n);
    for (int i = 0; i < n; i++)
    {
        if (p.size() == l)
        {
            p.push(p.top() + arr[i]);
            p.pop();
        }
    }
    cout << (p.top() >= round ? "Yes" : "No");
    return 0;
}