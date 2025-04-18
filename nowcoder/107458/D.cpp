// Nowcoder Compiler: C++（clang++18）
#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

template <typename T, typename TWriter>
void mex(const T begin, const T end, TWriter write) {
    bitset<100000> flags(0);
    int index = 0;
    for (auto it = begin; it != end; it++, write++) {
        flags[*it] = true;
        while (flags[index]) index++;
        *write = index;
    }
}

template <typename T, typename TOrigin>
bool mexChk(const T begin, const T end, TOrigin origin) {
    bitset<100000> flags(0);
    int index = 0;
    for (auto it = begin; it != end; it++, origin++) {
        flags[*it] = true;
        while (flags[index]) index++;
        if (index != *origin) return false;
    }
    return true;
}

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int n;
    cin >> n;
    bitset<100000> fixed(0);
    auto nums = vector<int>(n);
    auto revNums = vector<int>(n);
    auto preMex = vector<int>(n);
    auto sufMex = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        revNums[nums[i]] = i;
    }
    mex(nums.cbegin(), nums.cend(), preMex.begin());
    mex(nums.crbegin(), nums.crend(), sufMex.begin());
    for (int i = 1; i < n; i++) {
        if (preMex[i] != preMex[i - 1]) {
            fixed[i] = true;
        }
        if (sufMex[i] != sufMex[i - 1]) {
            fixed[n - i - 1] = true;
        }
    }
    // for (auto pre : preMex) cerr << pre << " ";
    // cerr << endl;
    // for (auto suf : sufMex) cerr << suf << " ";
    // cerr << endl;
    if (fixed.count() == n) return cout << -1 << endl, 0;

    int l, r;
    auto qwq = vector<int>();
    for (int i = 0; i < n; i++) {
        if (fixed[i]) continue;
        qwq.push_back(nums[i]);
    }

    RESTART:
    for (l = qwq.size() - 2; l >= 0; l--) {
        if (qwq[l] < qwq[l + 1]) break;
    }
    for (r = qwq.size() - 1; r > l; r--) {
        if (qwq[r] > qwq[l]) break;
    }
    swap(qwq[l], qwq[r]);
    sort(qwq.begin() + l + 1, qwq.end());

    {
        auto i = 0;
        for (auto qvq : qwq) {
            while (fixed[i]) i++;
            nums[i++] = qvq;
        }
    }
    if (!mexChk(nums.cbegin(), nums.cend(), preMex.cbegin())) goto RESTART;
    if (!mexChk(nums.crbegin(), nums.crend(), sufMex.cbegin())) goto RESTART;

    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}