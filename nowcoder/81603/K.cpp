#include <iostream>
#include <string>

using namespace std;

bool sequenceEqual(const string& str, int& begin)
{
    int begin2 = begin;
    if (str.size() - begin2 < 3)
        return false;
    if (str[begin2] != 'a' || str[begin2 + 1] != 'v' || str[begin2 + 2] != 'a')
        return false;
    if (str.size() - begin2 >= 5 && str[begin2 + 3] == 'v' && str[begin2 + 4] == 'a')
    {
        begin = begin2 + 5;
        return true;
    }
    begin = begin2 + 3;
    return true;
}

inline void solve()
{
    string str;
    int begin = 0;
    cin >> str;
    while (begin != str.size() && sequenceEqual(str, begin));
    cout << (begin == str.size() ? "Yes" : "No") << endl;
}

int main()
{
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #endif
    int batch;
    cin >> batch;
    while (batch--)
        solve();
    return 0;
}