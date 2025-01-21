#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

int main()
{
    double x, y, t, a, b, c, result;
    cin >> x >> y >> t >> a >> b >> c;
    if (x <= t)
        result = (100 - x) / c;
    else
    {
        result = (100 - x) / b;
        result = min(result, (x - t) / y + (100 - t) / c);
    }
    cout << fixed << setprecision(9) << result;
    return 0;
}