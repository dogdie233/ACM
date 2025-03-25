#include <bits/stdc++.h>

using namespace std;

vector<int> aiArr;
vector<int> prefixSum;  // 前缀和，prefixSum[i]表示从头跑到prefixSum[i] !结束! 的总长度

inline int solve(int l, int u) {
    // expectedSum是期望的总长度的前缀和
    // 最好的情况下自然是正好跑u长度，所以期望的总长度的前缀和就是
    // 跑道i长度的前缀和 - 跑道i的长度 + 体力值
    int expectedSum = prefixSum[l] - aiArr[l] + u;

    // 我们通过二分查找找到第一个大于等于expectedSum的前缀和，+l是因为我们可以直接跳过前面的l个跑道来二分
    // 这里有三种可能
    //  1. 找到了，而且这个位置的前缀和正好等于expectedSum，那么这个位置就是我们要找的位置
    //  2. 找到了，而且这个位置的前缀和大于expectedSum，说明我们跑完第i个跑道后已经超过了期望的总长度，已经开始适得其反了
    //  3. 没找到，说明我们跑完所有的跑道后还没达到期望的总长度（体力太多了，跑完所有的跑道都没事）
    auto endIt = lower_bound(prefixSum.begin() + l, prefixSum.end(), expectedSum);
    if (*endIt == expectedSum) {  // 第一种情况
        return endIt - prefixSum.begin();
    }
    if (endIt == prefixSum.end()) {  // 第三种情况
        return endIt - prefixSum.begin() - 1;
    }

    // 这里我们关注一下第二种情况，虽然我们跑完之后适得其反了，但是我们还是 !有可能! 通过跑完这个跑道获得更多的成长
    // 例子：endIt为第3个跑道，长度为10，在我们跑完第2个跑道的时候，我们还有9的体力，我们如果跑完第3个跑道
    // 虽然最后成长已经变成了-1，但是在跑整个第3跑道的过程中，我们的成长是8 7 6 5 4 3 2 1 0 -1，显然总和是一个正数，所以我们当然要跑完第3个跑道
    // 当然，也可能在跑完第3个跑道之后能力负增长
    // 例子：endIt为第3个跑道，长度为10，在我们跑完第2个跑道的时候，我们还有1的体力，我们如果跑完第3个跑道
    // 我们跑完整个第三跑道的成长是 0 -1 -2 -3 -4 -5 -6 -7 -8 -9，显然总和是一个负数，所以我们当然不跑第3个跑道
    // 所以我们要分别计算这两种情况，取最大值
    if (endIt - prefixSum.begin() == l) {  // 跑完l都适得其反了，太虚了，但是l是必须跑的，所以不用算了，直接返回l
        return endIt - prefixSum.begin();
    }
    auto prevK = *prev(endIt) - prefixSum[l] + aiArr[l];  // 跑完l~endIt-1的总和
    auto nextK = *endIt - prefixSum[l] + aiArr[l];  // 跑完l~endIt的总和
    // 为什么这里要+1？因为-1 0 1存在0这个空缺，
    return u - prevK + 1 > nextK - u ? endIt - prefixSum.begin() : endIt - prefixSum.begin() - 1;
}

int main() {
    int n, q;
    cin >> n;

    aiArr = vector<int>(n);
    prefixSum = vector<int>(n);

    for(auto& num : aiArr) {
        cin >> num;
    }
    
    prefixSum[0] = aiArr[0];
    for (auto i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + aiArr[i];
    }

    cin >> q;
    while (q--) {
        int l, u;
        cin >> l >> u;
        l -= 1;  // 题目的l是从1开始的，我们要转换成从0开始（因为我习惯数组从0开始 XD）
    
        auto ansR = solve(l, u);
        cout << (ansR + 1) << ' ';  // 因为我们的答案是从0开始的，所以要+1
    }
}