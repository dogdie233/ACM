#include <iostream>

using namespace std;

int main()
{
    int _;
    cin >> _;
    while (_--)
    {
        int a, b, n;
        cin >> a >> b >> n;
        n -= min(b / 2, n / 3) * 3;
        n -= min(a, n);
        cout << (n ? "NO" : "YES") << endl;
    }
}