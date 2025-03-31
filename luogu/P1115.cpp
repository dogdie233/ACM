#include <iostream>
#include <vector>

using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int n, dp = 0, num, maxx = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        dp = max(dp + num, num);
        maxx = max(dp, maxx);
    }
    cout << maxx << endl;
    return 0;
}