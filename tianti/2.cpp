#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    char ch;
    cin >> n >> ch;
    auto layer = (int)sqrt((n + 1) / 2);
    auto remain = n - (2 * layer * layer - 1);

    auto printLayer = [&](int l) {
        for (auto j = l; j < layer; j++) {
            cout << ' ';
        }
        for (auto j = l * 2 - 1; j > 0; j--)
            cout << ch;
        cout << endl;
    };
    for (auto i = layer; i > 1; i--) {
        printLayer(i);
    }
    if (n != 0) {
        printLayer(1);
    }
    for (auto i = 2; i <= layer; i++) {
        printLayer(i);
    }
    cout << remain;
    return 0;
}