#include <iostream>
#include <limits>

using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int64_t n0, n1, m, ans = numeric_limits<decltype(ans)>().max(), roooooomG;
    cin >> n0 >> n1 >> m;

    if (n0 == 0 && n1 == 0) {
        return cout << (m != 0 ? "No Solution" : "0 0"), 0;
    }
    if (n0 == 1 || n1 == 1) {
        return cout << "No Solution", 0;
    }
    if (n0 == 0) {
        auto j = n1 / m;
        if (j * m != n1 || j == 1) {
            return cout << "No Solution", 0;
        }
        return cout << "0 " << j, 0;
    }
    
    for (auto roomG = 1; roomG < m; roomG++) {
        auto roomB = m - roomG;
        auto g = n0 / roomG;
        auto b = n1 / roomB;

        if (g < 2 || b < 2 || n0 % roomG != 0 || n1 % roomB != 0) continue;
        if (abs(g - b) < ans) {
            ans = abs(g - b);
            roooooomG = roomG;
        }
    }

    if (ans == numeric_limits<decltype(ans)>().max()) {
        return cout << "No Solution", 0;
    }
    return cout << roooooomG << ' ' << (m - roooooomG), 0;
}