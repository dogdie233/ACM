#include <iostream>
#include <vector>
#include <algorithm>

typedef elem_t long long;

int main() {
    elem_t n, ans = 0;
    std::cin >> n;
    auto vec = std::vector<elem_t>(n);
    for (auto& elem : vec) {
        std::cin >> elem;
    }
    
    std::sort(vec.begin(), vec.end());

    for (int i = 0; i < n; i++) {
        ans += vec[i] * (i % 2 == 0 ? 1 : -1);
    }

    std::cout << ans;
    return 0;
}