// Nowcoder Compiler: C++（clang++18）
#include <iostream>
#include <vector>

using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto& x : arr) {
        cin >> x;
    }

    int zeroCount = 1;
    for (int begin = 0; begin < n; begin += zeroCount) {
        zeroCount = 1;
        if (arr[begin] != 0) {
            if (begin != 0 && abs(arr[begin] - arr[begin - 1]) != 1) {
                cout << "-1" << endl;
                return 0;
            }
            continue;
        }

        for (; begin + zeroCount < n && arr[begin + zeroCount] == 0; zeroCount++);

        if (begin == 0 && zeroCount >= n) {
            for (int i = 0; i < n; i++) {
                arr[i] = i % 2 + 1;
            }
            break;
        }

        if (begin + zeroCount >= n) {
            for (int i = 0; i < zeroCount; i++) {
                arr[begin + i] = arr[begin - 1] + ((i + 1) % 2);
            }
            break;
        }

        if (begin == 0) {
            for (int i = 1; i <= zeroCount; i++) {
                arr[zeroCount - i] = arr[zeroCount] + (i % 2);
            }
            continue;
        }

        auto diff = abs(arr[begin + zeroCount] - arr[begin]);
        if (diff > zeroCount + 1) {
            cout << "-1" << endl;
            return 0;
        }
        if (diff < zeroCount + 1) {
            if ((zeroCount - diff) % 2 == 0) {
                cout << "-1" << endl;
                return 0;
            }
            auto cnt = (zeroCount - diff + 1) & ~1;
            for (int i = 0; i < cnt; i++) {
                arr[begin + i] = arr[begin - 1] + ((i + 1) % 2);
            }
            begin += cnt;
            zeroCount -= cnt;
        }

        auto sign = arr[begin + zeroCount + 1] > arr[begin] ? 1 : -1;
        for (int i = 0; i < zeroCount; i++) {
            arr[begin + i] = arr[begin + i - 1] + sign;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}