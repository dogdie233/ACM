#include<bits/stdc++.h>
 
using namespace std;

void dfs(uint32_t val, uint32_t step, uint32_t &ans)
{
    if (step >= ans) return;

    uint32_t down = sqrt((double)val);
    if (down == 1)
        ans = min(step + val - 1, ans);
    else
        dfs(down, step + 1 + (val - (down * down)), ans);
    
    uint32_t up = down + 1;
    uint32_t mulRes;
    if (__builtin_umul_overflow(up, up, &mulRes)) return;
    dfs(up, step + 1 + (mulRes - val), ans);
}

int main()
{
    uint32_t target, ans = UINT32_MAX;
    cin >> target;

    if (target == 1) return cout << 0, 0;

    dfs(target, 0, ans);
    cout << ans;

    return 0;
}