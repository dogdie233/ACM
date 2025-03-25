#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    auto a = unordered_set<uint32_t>();
    auto b = unordered_set<uint32_t>();
    auto walked = unordered_set<uint32_t>();
    uint32_t cnt = 0, target;
    cin >> target;
    if (target == 1) return cout << 0, 0;
    
    b.insert(1);
    walked.insert(0);
    while (b.size() != 0)
    {
        a.swap(b);
        cnt++;
        b.clear();
        for (auto val : a)
        {
            walked.insert(val);
            uint32_t opResult;
            if (!__builtin_umul_overflow(val, val, &opResult))
            {
                if (opResult == target) return cout << cnt, 0;
                if (walked.find(opResult) == walked.end()) b.insert(opResult);
            }
            opResult = val + 1;
            if (opResult == target) return cout << cnt, 0;
            if (walked.find(opResult) == walked.end()) b.insert(opResult);
            opResult = val - 1;
            if (opResult == target) return cout << cnt, 0;
            if (walked.find(opResult) == walked.end()) b.insert(opResult);
        }
    }

    return 0;
}