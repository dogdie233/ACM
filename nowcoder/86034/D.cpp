#include <iostream>
#include <numeric>

using namespace std;

char astr[1000000];

int main()
{
    long long a = 0, b;
    cin >> astr >> b;
    for (int i = 0; astr[i]; i++)
        a = (a * 10 + astr[i] - '0') % b;
    cout << gcd(b, a);
    return 0;
}