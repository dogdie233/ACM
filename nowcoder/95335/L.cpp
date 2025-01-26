#include <bits/stdc++.h>

using namespace std;

const int N = 7;

int nodes[N + 1];

int main()
{
    nodes[0] = 1;
    for (int i = 1; i <= N; i++)
        nodes[i] = nodes[i - 1] + i + 1;

    int n, layer = 0, node = 1;
    cin >> n;

    cout << "Yes" << endl;
    cout << node << ' ';

    // 开始时向右下
    for (int stopLayer = 1; stopLayer <= n; stopLayer++)
    {
        while (layer < n)
            cout << (node += (++layer + 1)) << ' ';

        // 往左再往右上
        while (true)
        {
            cout << --node << ' ';
            if (layer == stopLayer)
                break;
            cout << (node -= layer--) << ' ';
        }
    }
    
    for (; layer != 0; layer--)
        cout << (node -= layer) << ' ';

    return 0;
}