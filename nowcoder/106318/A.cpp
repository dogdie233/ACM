// Nowcoder Compiler: C++（clang++18）
#include <iostream>
#include <stdint.h>

using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int64_t a, b, c;
    cin >> a >> b >> c;
    cout << (a * b <= c ? "YES" : "NO") << endl; 
    return 0;
}