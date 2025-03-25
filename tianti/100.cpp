#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> points(m);
    for (auto& p : points) {
        cin >> p;
    }
    auto sum = accumulate(points.begin(), points.end(), 0);
    cout << max(0, sum - n * (m - 1)) << endl;

    return 0;
}