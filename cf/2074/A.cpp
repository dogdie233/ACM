#include <iostream>
#include <iterator>

using namespace std;

int arr[4];

inline void solve() {
    for (auto& num : arr) {
        cin >> num;
    }
    for (int i = 1; i < std::size(arr); ++i) {
        if (arr[i] != arr[i - 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}