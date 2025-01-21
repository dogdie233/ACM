#include <iostream>
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    if (n < 3)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    int m = n / 2;
    if (n & 1)
        cout << m << ' ' << (m + 1);
    else
        cout << (m - 1) << ' ' << (m + 1);
    return 0;
}