#include <iostream>

using namespace std;

int main() {
    char ch;
    int cnt[10] = {0};
    while (ch = cin.get(), ch != '\n') {
        cnt[ch - '0']++;
    }
    for (int i = 0; i < 10; i++) {
        if (cnt[i] != 0) {
            cout << i << ":" << cnt[i] << endl;
        }
    }
    return 0;
}