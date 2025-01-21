#include <iostream>

using namespace std;

int main()
{
    string s;
    bool arr[26] = { 0 };
    cin >> s;
    for (auto &c : s)
        arr[c - 'a'] = true;
    
    int n = 0;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] && i != 'i' - 'a')
            n++;
    }
    cout << n;
    return 0;
}