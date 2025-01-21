#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

ll getFactorCount(ll num, ll n)
{
    ll count = 0, ed = sqrt(num);
    for (int i = 1; i <= ed; i++)
    {
        if (num % i == 0)
        {
            count += i <= n;
            count += num / i <= n;
        }
    }
    if (ed * ed == num && ed <= n)
        count--;
    return count;
}

int main()
{
    ll n, x;
    cin >> n >> x;
    cout << (getFactorCount(x, n) & 1 ? "ON" : "OFF");
    
    return 0;
}