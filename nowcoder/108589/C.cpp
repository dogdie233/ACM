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
    if (n == 1) {
        return cout << "-1" << endl, 0;
    } else if (n == 2) {
        return cout << "2 1" << endl, 0;
    } else if (n == 3) {
        return cout << "3 1 2" << endl, 0;
    } else {
        return cout << "-1" << endl, 0;
    }
    return 0;
}