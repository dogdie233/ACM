#include <iostream>
#include <string>

using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    string sa(10000, 0);
    string sb(10000, 0);
    cin.getline(&sa[0], sa.size()).getline(&sb[0], sb.size());
    bool removeChars[256] = {0};
    for (auto c : sb) {
        removeChars[c] = true;
    }
    for (auto c : sa) {
        if (!removeChars[c]) {
            cout << c;
        }
    }

    return 0;
}