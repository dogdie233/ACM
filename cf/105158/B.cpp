#include <iostream>

using namespace std;

int arr[200000];

int find_smallest(int l, int r)
{
    int min = l;
    for (int i = l + 1; i < r; i++)
    {
        if (arr[i] <= arr[min])
            min = i;
    }
    return min;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int l = 0, coin = 1, ans = 0;
    do
    {
        while (arr[l] > coin && l + 1 < n)
        {
            coin++;
            l++;
        }
        int nl = find_smallest(l, n);
        coin += nl - l;
        ans += coin / arr[nl];
        coin -= (coin / arr[nl]) * arr[nl];
        l = nl;
    } while (l < n - 1);
    cout << ans;
    return 0;
}