#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <map>
#include <vector>
#include <algorithm>
#include <ranges>
#include <cmath>
#include <numeric>

typedef long long num_t;

using namespace std;

const int MAXN = 100;

enum class OperationType : uint8_t {
    Drop = 0,
    Row = 1,
    Col = 2
};

struct Table {
    int operationCount;
    OperationType operations[MAXN];
};

struct Solution {
    vector<int>& nums;
    map<num_t, Table> tables;
    int nowOperationsCount;
    OperationType nowOperations[MAXN];
    num_t dfsSaveRowSum, dfsSaveColSum;
    num_t searchingSum;
    num_t maxSum;

    Solution(vector<int>& nums) : nums(nums), nowOperationsCount(0), dfsSaveRowSum(0), dfsSaveColSum(0) {
        memset(nowOperations, 0, sizeof(nowOperations));
        
        num_t sum = accumulate(nums.begin(), nums.end(), 0);
        auto dp = vector<bool>(sum / 2 + 1, false);
        dp[0] = true;

        num_t maxSubSum = 0;
        for (auto& num : nums) {
            for (auto i = sum / 2; i >= num; i--) {
                dp[i] = dp[i] || dp[i - num];
                if (dp[i]) {
                    maxSubSum = max(maxSubSum, i);
                }
            }
        }

        maxSum = maxSubSum * (sum - maxSubSum);
    }

    Table* solve(num_t sum) {
        if (sum > maxSum) {
            return nullptr;
        }

        if (tables.find(sum) != tables.end()) {
            return &tables[sum];
        }

        searchingSum = sum;
        if (!dfs(0)) {
            return nullptr;
        }

        return solve(sum); // refind in tables;
    }
    
    bool dfs(int index) {
        if (index >= nums.size()) {
            return false;
        }

        num_t sum;
        if (nowOperationsCount > index) {
            goto FROM_CHECKPOINT;
        }

        for (nowOperations[index] = OperationType::Drop; nowOperations[index] <= OperationType::Col; nowOperations[index] = static_cast<OperationType>(static_cast<uint8_t>(nowOperations[index]) + 1)) {
            nowOperationsCount = index + 1;
            if (nowOperations[index] == OperationType::Row) {
                dfsSaveRowSum += nums[index];
            } else if (nowOperations[index] == OperationType::Col) {
                dfsSaveColSum += nums[index];
            }
            sum = dfsSaveRowSum * dfsSaveColSum;
            if (tables.find(sum) == tables.end()) {
                saveToTable();
            }
            if (sum == searchingSum) {
                return true;
            }

            FROM_CHECKPOINT:
            if (dfs(index + 1)) {
                return true;
            }
            if (nowOperations[index] == OperationType::Row) {
                dfsSaveRowSum -= nums[index];
            } else if (nowOperations[index] == OperationType::Col) {
                dfsSaveColSum -= nums[index];
            }
        }
        return false;
    }

    void saveToTable() {
        auto sum = dfsSaveRowSum * dfsSaveColSum;
        tables[sum] = {};
        auto table = &tables[sum];
        table->operationCount = nowOperationsCount;
        memcpy(table->operations, nowOperations, sizeof(nowOperations));
    }
};

map<num_t, Solution> solutions;

int main() {
    int n, m;
    cin >> n >> m;
    auto nums = vector<int>(n);
    for (auto& num : nums) {
        cin >> num;
    }
    sort(nums.begin(), nums.end());
    
    auto row = vector<int>();
    auto col = vector<int>();
    row.reserve(n);
    col.reserve(n);

    auto solution = Solution(nums);
    for (auto i = 0; i < m; i++) {
        num_t sum;
        cin >> sum;
        auto table = solution.solve(sum);

        if (table == nullptr) {
            cout << "No\n";
            continue;
        }

        row.clear();
        col.clear();
        for (auto j = 0; j < table->operationCount; j++) {
            if (table->operations[j] == OperationType::Row) {
                row.push_back(nums[j]);
            } else if (table->operations[j] == OperationType::Col) {
                col.push_back(nums[j]);
            }
        }

        cout << "Yes\n";
        cout << row.size() << " " << col.size() << "\n";
        for (auto& num : row) {
            cout << num << " ";
        }
        cout << "\n";
        for (auto& num : col) {
            cout << num << " ";
        }
        cout << "\n";
    }
}