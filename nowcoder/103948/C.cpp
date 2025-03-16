#include <iostream>
#include <string>
#include <cmath>

int main() {
    #ifdef ONLINE_JUDGE
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif

    int n;
    std::string str;
    std::cin >> n;
    while (n--) {
        int slop = 0;
        std::cin >> str;

        for (int i = 1; i < str.size(); i++) {
            slop += std::abs(str[i] - str[i - 1]);
        }

        std::cout << (slop > 4 ? "No" : "Yes") << '\n';
    }
}