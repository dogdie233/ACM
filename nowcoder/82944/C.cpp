#include <iostream>
#include <algorithm>

using namespace std;
typedef long long i64;

i64 arr[100000];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    for (int i = 0; i < n / 2; i++)
        arr[i] = arr[i] * arr[(n & ~1) - i - 1];
    if (n & 1)
        arr[n / 2] = arr[n - 1];
    sort(arr, arr + n / 2 + (n & 1));

    cout << arr[n / 2 - 1 + (n & 1)] - arr[0];
}