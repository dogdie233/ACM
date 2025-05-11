// Nowcoder Compiler: C++（clang++18）
#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int64_t k, endd;
    cin >> k;
    endd = (int64_t)sqrt(k) + 1;

    for (int64_t a = 1; a <= endd; a++) {
        auto divv = div(k - a, a + 1);
        if (divv.rem == 0 && divv.quot > 0) {
            return cout << (a + divv.quot) << ' ' << (a * divv.quot) << endl, 0;
        }
    }
    return cout << "-1" << endl, 0;
}