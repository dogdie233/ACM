#include <iostream>

using namespace std;

int main() {
    int a, b, w;
    cin >> a >> b >> w;
    cout << ((a == w || b == w || a + b == w || a == b + w || b == a + w) ? "Yes" : "No");
    return 0;
}