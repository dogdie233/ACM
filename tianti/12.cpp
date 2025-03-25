#include <iostream>

using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int n;
    cin >> n;
    cout << "2^" << n << " = " << (1 << n) << endl;
    return 0;
}