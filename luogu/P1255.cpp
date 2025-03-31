#include <iostream>
#include <stdint.h>

using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int64_t n, arr[3] = { 0 };
    cin >> n;
    arr[0] = 1; arr[1] = 2;
    for (int i = 2; i < n; i++) {
        arr[i % 3] = arr[(i - 1) % 3] + arr[(i - 2) % 3];
    }
    cout << arr[(n + 2) % 3] << endl;
    return 0;
}