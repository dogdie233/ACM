#include <iostream>
#include <ranges>

using namespace std;

int arr[501];

inline void solve()
{
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++)
        cin >> arr[i];
    arr[n] = 1e9;
    for (int i = n - 1; i > 0; i--)
        arr[i] = arr[i + 1] - arr[i - 1];
    for (auto &i : ranges::subrange(arr + 1, arr + n + 1))
        cout << i << ' ';
    cout << endl;
}

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #endif

    int batch;
    cin >> batch;
    while (batch--)
        solve();
    return 0;
}