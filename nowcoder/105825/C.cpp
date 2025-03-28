#include <iostream>
#include <set>

using namespace std;

int main() {
    int q, k, value;
    cin >> q;
    set<int> arr;
    for (int i = 0; i < q; i++) {
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> value;
            if (arr.contains(value)) {
                return cout << "NO" << endl, 0;
            }
            arr.insert(value);
        }
    }
    for (auto itPrev = arr.begin(), itNext = ++arr.begin(); itNext != arr.end(); itPrev++, itNext++) {
        if (*itNext - *itPrev != 1) {
            return cout << "NO" << endl, 0;
        }
    }
    return cout << "YES" << endl, 0;
}