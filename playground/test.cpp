#include <iostream>
#include <limits>

using namespace std;

int main() {
    unsigned int n;
    cout << numeric_limits<decltype(n)>::digits << '\n';
}