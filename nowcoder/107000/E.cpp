// Nowcoder Compiler: C++（clang++18）
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif

    int n, m;
    cin >> n >> m;
    
    vector<string> grid(n);
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<vector<int>> ops;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '0') {
                if (j + 1 < m) {
                    grid[i][j] = grid[i][j] == '0' ? '1' : '0';
                    grid[i][j + 1] = grid[i][j + 1] == '0' ? '1' : '0';
                    ops.push_back({ i + 1, j + 1, i + 1, j + 2});
                } else if (i + 1 < n) {
                    grid[i][j] = grid[i][j] == '0' ? '1' : '0';
                    grid[i + 1][j] = grid[i + 1][j] == '0' ? '1' : '0';
                    ops.push_back({ i + 1, j + 1, i + 2, j + 1});
                }
            }
        }
    }
    
    bool possible = true;
    for(int i = 0; i < n && possible; i++) {
        for(int j = 0; j < m && possible; j++) {
            if(grid[i][j] == '0') {
                possible = false;
            }
        }
    }
    
    if(!possible) {
        cout << -1 << endl;
    } else {
        cout << ops.size() << endl;
        for(const auto& op : ops) {
            cout << op[0] << " " << op[1] << " " << op[2] << " " << op[3] << endl;
        }
    }
    
    return 0;
}