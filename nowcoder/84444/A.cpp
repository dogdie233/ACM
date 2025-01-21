#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    cout << a + min(b, a / 2) << endl;

    return 0;
}