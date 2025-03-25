#include <iostream>
#include <stdint.h>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

int main() {
    int64_t n, startFactor, product, sqrtN;
    cin >> n;
    sqrtN = (int)sqrt(n);
    startFactor = n;
    
    int maxCount = 1, count = 0;
    for (auto start = sqrtN; start > 1; start--) {
        for (count = 0, product = 1; product <= n; product *= (start + count++)) {
            if (n % product == 0 && count >= maxCount) {
                maxCount = count;
                startFactor = start;
            }
        }
    }
    if (startFactor == numeric_limits<int64_t>::max()) {
        startFactor = n;
        maxCount = 1;
    }
    
    cout << maxCount << endl;
    if (maxCount > 0) {
        for (int i = 0; i < maxCount; i++) {
            cout << startFactor + i << (i != maxCount - 1 ? "*" : "\n");
        }
    }
    
    return 0;
}