#include <bits/stdc++.h>

using namespace std;

uint8_t arr[101][101];

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int y = 1; y <= n; y++)
        {
            getchar();
            for (int x = 1; x <= n; x++)
                arr[y][x] = getchar() - '0';
        }
        
    }
    return 0;
}