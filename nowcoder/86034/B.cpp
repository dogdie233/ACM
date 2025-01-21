#include <iostream>

using namespace std;

int main()
{
    while (cin.get() != '\n');
    int sum = 0, num;
    while (true)
    {
        num = cin.get() - '0';
        if (num < 0 && num != ' ' - '0')
            break;
        sum += max(0, num);
    }
    cout << ((sum % 3) == 0 ? "YES" : "NO");
    return 0;
}