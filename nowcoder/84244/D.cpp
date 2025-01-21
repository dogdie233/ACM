#include <iostream>

using namespace std;
typedef long long ll;

int balls[100002];
int lastpos[100002];

int main()
{
    int n, k;
    ll ans = 1;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> balls[i];
    
    int l = 1, r = 1;
    lastpos[balls[1]] = 1;
    while (r < n)
    {
        while (r < n && (lastpos[balls[r + 1]] == 0 || r + 1 - lastpos[balls[r + 1]] <= k))
        {
            ans += (++r) - l + 1;
            // cerr << '[' << l << ", " << r << ']' << endl;
            lastpos[balls[r]] = r;
        }
        l = max(l, lastpos[balls[r + 1]] + 1);
        lastpos[balls[r + 1]] = r + 1;
    }

    cout << ans;

    return 0;
}