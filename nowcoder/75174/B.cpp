#include <iostream>

using namespace std;

int main()
{
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #endif
    
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int ans = 5;
    ans = min(ans, (int)((s1[0] != 'd') + (s1[1] != 'f') + (s1[2] != 's') + (s2[0] != 'f') + (s3[0] != 's')));
    ans = min(ans, (int)((s2[0] != 'd') + (s2[1] != 'f') + (s2[2] != 's') + (s1[1] != 'd') + (s3[1] != 's')));
    ans = min(ans, (int)((s3[0] != 'd') + (s3[1] != 'f') + (s3[2] != 's') + (s1[2] != 'd') + (s2[2] != 'f')));
    cout << ans;
}