#include <iostream>
#include <iomanip>

using namespace std;
using ft = double;

double cal_sqr_distance(double x1, double y1, double x2, double y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main()
{
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #endif
    int batch;
    cin >> batch;
    while (batch--)
    {
        ft l, x, y;
        cin >> l >> x >> y;
        ft sqrL = l * l;
        if (cal_sqr_distance(x, y, 0, 0) <= sqrL)
        {
            cout << "Yes\n0\n";
            continue;
        }
        if (cal_sqr_distance(x, y, l, 0) <= sqrL)
        {
            cout << "Yes\n" << fixed << l << '\n';
            continue;
        }
        if (0 <= x && x <= l && max(x, l - x) >= abs(y))
        {
            cout << "Yes\n" << fixed << x << '\n';
            continue;
        }
        cout << "No\n";
    }
    return 0;
}