// Nowcoder Compiler: C++（clang++18）
#include <iostream>

using namespace std;

int arr[10001];

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    cout << "1\n";
    int nextBeginIdx = 2;
    for (auto layer = 1; layer <= n; layer++) {
        auto nextLayerUsedCount = 0;
        for (; nextLayerUsedCount < arr[layer + 1] - 1; nextLayerUsedCount += 2) {
            cout << (nextBeginIdx + nextLayerUsedCount) << ' ' << (nextBeginIdx + nextLayerUsedCount + 1) << '\n';
        }
        if (nextLayerUsedCount == arr[layer + 1] - 1) {
            cout << (nextBeginIdx + nextLayerUsedCount) << " -1\n";
        }

        for (int i = (arr[layer + 1] + 1) / 2; i < arr[layer]; i++) {
            cout << "-1 -1\n";
        }
        nextBeginIdx += arr[layer + 1];
    }

    return 0;
}