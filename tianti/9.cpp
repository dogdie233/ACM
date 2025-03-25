#include <iostream>
#include <stdint.h>
#include <numeric>

using namespace std;

int main() {
    int n;
    int64_t fz, fm, ansFz = 0, ansFm = 0;
    scanf("%d", &n);
    scanf("%ld/%ld", &ansFz, &ansFm);
    for (int i = 1; i < n; i++) {
        scanf("%ld/%ld", &fz, &fm);
        if (fz == 0) {
            continue;
        }
        auto lcmValue = lcm(fm, ansFm);
        ansFz = ansFz * (lcmValue / ansFm) + fz * (lcmValue / fm);
        ansFm = lcmValue;
        auto gcdValue = gcd(abs(ansFz), ansFm);
        ansFz /= gcdValue;
        ansFm /= gcdValue;
    }
    
    auto integerPart = ansFz / ansFm;
    ansFz %= ansFm;
    if (integerPart != 0) {
        cout << integerPart;
        if (ansFz != 0) {
            cout << " ";
        }
    }
    if (ansFz != 0) {
        cout << ansFz << "/" << ansFm;
    }
    cout << '\n';
    
    return 0;
}