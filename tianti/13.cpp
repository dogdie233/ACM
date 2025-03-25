#include <iostream>

using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    uint64_t N, owo = 1, sum = 0;
    cin >> N;
    for (int n = 1; n <= N; n++) {
        owo *= n;
        sum += owo;
    }
    cout << sum;
    return 0;
}