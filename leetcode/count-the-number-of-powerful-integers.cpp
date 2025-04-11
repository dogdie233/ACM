#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        auto number = string(31, '0');
        for (auto i = 1; i <= s.length(); i++) {
            number[number.length() - i] = s[s.length() - i];
        }
        auto startStr = to_string(start);
        for (auto i = s.length() + 1; i <= startStr.length(); i++) {
            number[number.length() - i] = startStr[startStr.length() - i];
        }

        auto advance = [&](auto&& self, int index) -> void {
            number[index]++;
            if (number[index] > '9' || number[index] - '0' > limit) {
                number[index] = '0';
                self(self, index - 1);
            }
        };

        auto rootIndex = number.length() - 1 - s.length();
        auto num = stoll(number);
        if (num < start || any_of(number.begin(), number.end(), [limit](char c) { return c - '0' > limit; })) {
            advance(advance, rootIndex);
        }
        auto ans = 0ll;
        while ((num = stoll(number)) <= finish) {
            ans += num >= start;
            advance(advance, rootIndex);
        }
        return ans;
    }
};