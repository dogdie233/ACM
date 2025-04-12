#include <bits/stdc++.h>  

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    auto i = min(find(s1.begin(), s1.end(), '#') - s1.begin(), find(s2.begin(), s2.end(), '#') - s2.begin());
    int ans = 0;
    for (int j = i + 1; j < s1.size(); j++) {
        if (s1[j] != '#' && s2[j] != '#') continue;
        if (s1[j] == '#' && s2[j] == '#') {
            ans += j - i - 1;
            goto NYA;
        }
        if (s1[j] == '#') {
            ans += j - i - 1;
            if (s1[i] != '#') {
                s2[j] = '#';
                ans++;
            }
            goto NYA;
        }
        if (s2[j] == '#') {
            ans += j - i - 1;
            if (s2[i] != '#') {
                s1[j] = '#';
                ans++;
            }
        }

        NYA:
        i = j;
    }
    cout << ans << endl;
    return 0;
}