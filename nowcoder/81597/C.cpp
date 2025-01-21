#include <iostream>
#include <string>

using namespace std;

unsigned char arr[1000001];

constexpr inline int toCnt(unsigned char c)
{
    return (c >> 1) + (c & 1);
}

int main()
{
    int n;
    cin >> n;
    while (cin.get() != '\n');
    arr[0] = 0b11;
    for (int i = 1; i <= n; i++)
        arr[i] = cin.get() == 'R' ? 0b01 : 0b00;
    while (cin.get() != '\n');
    for (int i = 1; i <= n; i++)
        arr[i] |= cin.get() == 'R' ? 0b10 : 0b00;

    int ans = 0, curr = 0, prevOneIdx = -1;
    for (int i = 1; i <= n; i++)
    {
        if ((arr[i] & arr[i - 1]) == 0b00)
        {
            ans = max(ans, curr);
            curr = 0;
            prevOneIdx = -1;
        }
        curr += toCnt(arr[i]);
        if (toCnt(arr[i]) == 1)
        {
            if (prevOneIdx != -1)
                curr -= (arr[prevOneIdx] != arr[i]) ^ (i - prevOneIdx - 1) & 1;
            prevOneIdx = i;
        }
    }
    ans = max(ans, curr);
    cout << max(0, ans - 1);
    return 0;
}