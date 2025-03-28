#include <iostream>
#include <set>

using namespace std;

int main() {
    int q, k, value, prevValue;
    cin >> q;
    set<int> arr;
    for (int i = 0; i < q; i++) {
        cin >> k;
        prevValue = -1;
        for (int i = 0; i < k; i++) {
            cin >> value;
            if (value <= prevValue || arr.contains(value)) {
                return cout << "NO" << endl, 0;
            }
            arr.insert(value);
            prevValue = value;
        }
    }
    for (auto itPrev = arr.begin(), itNext = ++arr.begin(); itNext != arr.end(); itPrev++, itNext++) {
        if (*itNext - *itPrev != 1) {
            return cout << "NO" << endl, 0;
        }
    }
    return cout << "YES" << endl, 0;
}