#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    // Compute prefix parity (0=even, 1=odd) for '0's and '1's
    vector<int> prefix_parity_0(n + 1, 0);
    vector<int> prefix_parity_1(n + 1, 0);
    
    for (int i = 0; i < n; i++) {
        prefix_parity_0[i + 1] = prefix_parity_0[i] ^ (s[i] == '0');
        prefix_parity_1[i + 1] = prefix_parity_1[i] ^ (s[i] == '1');
    }
    
    // For each parity combination, find the last position where it appears
    vector<vector<int>> last_pos(2, vector<int>(2, -1));
    for (int i = 0; i <= n; i++) {
        last_pos[prefix_parity_0[i]][prefix_parity_1[i]] = i;
    }
    
    int win_count = 0;
    
    // Check each possible prefix deletion by Red (1 to n)
    for (int k = 1; k <= n; k++) {
        int p0 = prefix_parity_0[k];
        int p1 = prefix_parity_1[k];
        
        // To get even counts of both '0' and '1', we need to find a position
        // with the same parity as position k, that comes after k
        if (last_pos[p0][p1] > k) {
            win_count++;
        }
    }
    
    double win_probability = static_cast<double>(win_count) / n;
    printf("%.6f\n", win_probability);
    
    return 0;
}