#include <iostream>
#include <algorithm>

using namespace std;

int arr[500000];

int main()
{
    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n, greater<int>());
    int round = (max(0, n - r) + (r - l - 1)) / (r - l);
    int pf = 0;
    while (round--)
    {
        while (pf < n && arr[pf] < 3)
            pf++;
        
        if (pf + l > n)
        {
            cout << "No";
            return 0;
        }
        for (int i = pf; i < pf + l; i++)
            arr[i] -= 2;
    }
    cout << "Yes";
    return 0;
}