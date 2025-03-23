#include <iostream>
#include <numeric>

using namespace std;

void solve() {
    unsigned long long a, b;
    cin >> a >> b;
    
    if (a == 0 || b == 0) {
        cout << "0\n";
        return;
    }
    
    if ((a ^ b) == 0 || ((a & b) == 0)) {
        cout << "1\n";
        return;
    }
    
    auto qaq = [&](const unsigned long long v) -> bool {
        if ((v & a) == 0 || (v & b) == 0) return true;
        if ((v ^ a) == 0 || (v ^ b) == 0) return true;
        return false;
    };

    auto orV = a | b;
    auto andV = a & b;
    auto xorV = a ^ b;
    auto gcdV = gcd(a, b);
    if (qaq(orV) || qaq(andV) || qaq(xorV) || qaq(gcdV)) {
        cout << "2\n";
        return;
    }
    
    cout << "3\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}