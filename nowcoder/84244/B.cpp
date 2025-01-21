#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    if ((n == 1 && m == 1) || m % 2 == 1 || n % 2 == 0)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}