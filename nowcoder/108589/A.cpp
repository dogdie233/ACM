// Nowcoder Compiler: C++（clang++18）
#include <iostream>

using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int n;
    cin >> n;
    cout << "m_";
    for (int i = 2; i < n; i++) {
        cout << 'a';
    }
    return 0;
}