#include <iostream>

using namespace std;

int arr[200001];

int main()
{
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    arr[x] = 0;
    int ans = 0, maxv = 0;
    for (int i = 1; i <= n; i++)
    {
        if (maxv == arr[i])
            ans++;
        else if (maxv < arr[i])
        {
            maxv = arr[i];
            ans = 1;
        } 
    }
    cout << ans;
    return 0;
}