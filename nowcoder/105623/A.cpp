#include <iostream>

using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int a, b, c;
    cin >> a >> b >> c;
    cout << (a > b && b < c ? "YES" : "NO") << endl;
    return 0;
}