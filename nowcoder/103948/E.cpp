#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Line {
    int l, r, idx;
};

int main() {
    int n;
    cin >> n;
    auto vec = vector<Line>(n);
    for (auto i = 0; i < n; i++) {
        cin >> vec[i].l >> vec[i].r;
        vec[i].idx = i + 1;
    }
    sort(vec.begin(), vec.end(), [](const Line& lhs, const Line& rhs) {
        return lhs.l != rhs.l ? lhs.l < rhs.l : lhs.r < rhs.r;
    });
    auto dye = vector<int>();
    auto dyeRight = 0;
    auto noDyeRight = 0;
    for (auto& elem : vec) {
        if (elem.l > dyeRight) {
            dyeRight = elem.r;
            dye.push_back(elem.idx);
            continue;
        } else if (elem.l > noDyeRight) {
            noDyeRight = elem.r;
            continue;
        }
        
        return cout << -1, 0;
    }

    cout << dye.size() << '\n';
    for (const auto& elem : dye) {
        cout << elem << ' ';
    }
    return 0;
}