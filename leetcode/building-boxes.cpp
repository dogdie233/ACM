#include <algorithm>
#include <cmath>

struct Layer {
    size_t l, more;

    size_t count() {
        return l * (l + 1) / 2 + more;
    }

    Layer(size_t l, size_t more) : l(l), more(more) {}
    Layer(size_t num) {
        l = static_cast<decltype(l)>((-1 + std::sqrt(1 + 8 * num)) / 2);
        more = num - l * (l + 1) / 2;
    }
};

Layer build_up(const Layer& layer) {
    return Layer(layer.l - 1, layer.more == 0 ? 0 : layer.more - 1);
}

bool check(int bottomCount, int n) {
    auto current = Layer(bottomCount);
    auto sum = 0ull;
    auto cnt = 0ull;
    while ((cnt = current.count()) != 0) {
        sum += cnt;
        if (sum >= n) return true;
        current = build_up(current);
    }
    return false;
}

class Solution {
public:
    int minimumBoxes(int n) {
        int l = 1, r = n;
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (check(mid, n)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};