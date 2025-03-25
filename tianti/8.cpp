#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int left, right, newLineCounter = 5, sum = 0;
    cin >> left >> right;
    for (auto i = left; i <= right; i++) {
        // cout << format("{:5}", i);  // 用不了format因为天梯赛的编译器虽然是C++20但是不支持format
        ostringstream ss;
        ss << i;
        string str = ss.str();
        for (auto j = 0; j < 5 - str.size(); j++) {
            cout << " ";
        }
        cout << i;

        if (--newLineCounter == 0) {
            cout << endl;
            newLineCounter = 5;
        }
        sum += i;
    }
    if (newLineCounter != 5) {
        cout << endl;
    }
    cout << "Sum = " << sum << endl;
    return 0;
}