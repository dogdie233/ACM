#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> pos;

int main()
{
    int n, num, cnt = 0, zeroCnt = 0;
    cin >> n;
    while (n--)
    {
        cin >> num;
        if (num == 0)
            zeroCnt++;
        else if (num < 0)
            cnt++;
        else
        {
            if (pos.find(num) == pos.end())
                pos.insert(num);
            else
                pos.erase(num);
        }
    }
    cnt -= pos.size();
    if (cnt < 0)
        cout << (abs(cnt) + (zeroCnt & 1));
    else
        cout << ((cnt + zeroCnt) & 1);
    return 0;
}