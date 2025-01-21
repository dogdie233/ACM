#include <iostream>
#include <map>

using namespace std;

int main()
{
    int t, n, v;
    map<int, int> m;
    cin >> t;
    while (t--)
    {
        cin >> n;
        while (n--)
        {
            cin >> v;
            m[v]++;
        }
        cout << ((m.size() == 2 && m.cbegin()->second == m.crbegin()->second) ? "Yes" : "No") << endl;
        m.clear();
    }
    return 0;
}