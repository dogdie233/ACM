#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #endif
    int n, q;
    cin >> n >> q;
    map<string, string> table;

    for (int i = 0; i < n; i++)
    {
        string type, varName;
        cin >> type >> varName;
        table[varName] = varName.substr(0, varName.size() - 1);
    }

    for (int i = 0; i < q; i++)
    {
        string queryName;
        cin >> queryName;

        string& typeName = table[queryName];
        size_t searchStart = 0, spanStart = 0, spanEnd = typeName.size();
        while (true)
        {
            searchStart = find(typeName.begin() + spanStart, typeName.begin() + spanEnd, '.') - typeName.begin();
            if (searchStart == string::npos)
                break;
            if (typeName[searchStart + 1] == 'f')  // first
            {
                spanStart = spanStart + 5;
                int pairCount = 0;
                while (typeName[spanEnd] != ',' || pairCount != 0)
                {
                    if (typeName[spanEnd] == '>')
                        pairCount++;
                    else if (typeName[spanEnd] == '<')
                        pairCount--;
                    spanEnd--;
                }
            }
            else  // second
            {
                int pairCount = 0;
                while (typeName[spanStart] != ',' || pairCount != 0)
                {
                    if (typeName[spanEnd] == '<')
                        pairCount++;
                    else if (typeName[spanEnd] == '>')
                        pairCount--;
                    spanStart++;
                }
                spanStart++;  // skip ','
            }
        }
        cout << typeName.substr(spanStart, spanEnd - spanStart) << '\n';
    }
    return 0;
}