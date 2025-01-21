#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
typedef long long i64;

const i64 mod = 1000000007;

int main()
{
    int n, k;
    i64 dp[1001] = { 0 }, cnt[1001] = { 0 };
    string s;
    cin >> n >> k >> s;
    
    cnt[0] = 1;
    for (char c : s)
    {
        for (int i = k; i > 0; i--)
        {
            cnt[i] = (cnt[i] + cnt[i - 1]) % mod;
            dp[i] += (dp[i - 1] * 10 + (c - '0') * cnt[i - 1]);
            dp[i] %= mod;
        }
    }

    cout << dp[k];
}