#include<iostream>

using namespace std;

const int mod = 1e9+7;

int arr[100000];

int main()
{
    int n, score = 0, pos = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    char c;
    while ((c = getchar()) > 32)
    {
        if (c == 'R')
            pos = min(pos + 1, n - 1);
        else
            pos = max(pos - 1, 0);
        score = (score + arr[pos]) % mod;
    }
    cout << score;
}