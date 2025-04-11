// Nowcoder Compiler: C++（clang++18）
#include <iostream>
#include <vector>

using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif

    int x, y, z;
    cin >> x >> y >> z;
    int total = x + y + z;
    
    auto input = vector<int>(total);
    for (int& num : input) {
        cin >> num;
    }

    auto result = vector<int>(total);
    auto remaining = vector<int>{ x, y, z };
    
    for (int i = 0; i < total; i++) {
        int bestMatch = 1;
        int minMatches = total;
        
        for (int type = 1; type <= 3; type++) {
            if (remaining[type - 1] > 0) {
                result[i] = type;
                remaining[type - 1]--;
                
                int matches = (type == input[i] ? 1 : 0);
                
                remaining[type - 1]++;
                
                if (matches < minMatches) {
                    minMatches = matches;
                    bestMatch = type;
                }
            }
        }
        
        result[i] = bestMatch;
        remaining[bestMatch - 1]--;
    }
    
    for (int i = 0; i < total; i++) {
        cout << result[i] << (i < total - 1 ? " " : "\n");
    }
    
    return 0;
}