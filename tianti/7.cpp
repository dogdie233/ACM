#include <iostream>

using namespace std;

char *strArr[128];

int main() {
    strArr['-'] = "fu";
    strArr['0'] = "ling";
    strArr['1'] = "yi";
    strArr['2'] = "er";
    strArr['3'] = "san";
    strArr['4'] = "si";
    strArr['5'] = "wu";
    strArr['6'] = "liu";
    strArr['7'] = "qi";
    strArr['8'] = "ba";
    strArr['9'] = "jiu";

    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    char ch;
    bool first = false;
    while (ch = cin.get(), ch != '\n') {
        if (first) {
            cout << " ";
        } else {
            first = true;
        }
        cout << strArr[ch];
    }
    return 0;
}