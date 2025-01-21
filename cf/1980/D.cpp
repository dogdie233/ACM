#include <iostream>

#define NO return cout << "NO\n", void()
#define YES return cout << "YES\n", void()

using namespace std;

int arr[200000];
int gcdarr[200000];

inline constexpr int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

inline bool test(int l, int n)
{
    while (l < n - 1)
    {
        if (gcdarr[l] < gcdarr[l - 1])
            return false;
        l++;
    }
    return true;
}

inline void solve()
{
    int n;
    cin >> n;
    cin >> arr[0];
    for (int i = 1; i < n; i++)
    {
        cin >> arr[i];
        gcdarr[i - 1] = gcd(arr[i - 1], arr[i]);
    }

    bool pass = true;
    for (int l = 1; l < n - 1; l++)
        pass &= gcdarr[l] >= gcdarr[l - 1];
    if (pass) YES;
    
    for (int l = 1; l < n - 1; l++)
    {
        if (gcdarr[l] >= gcdarr[l - 1])
            continue;

        if (l - 2 >= 0)
            gcdarr[l - 2] = gcd(arr[l - 2], arr[l]);
        gcdarr[l - 1] = gcdarr[l];

        if (test(max(0, l - 2), n))
            YES;
        
        if (l - 2 >= 0)
            gcdarr[l - 2] = gcd(arr[l - 2], arr[l - 1]);
        gcdarr[l - 1] = gcd(arr[l - 1], arr[l]);
    }

    for (int l = 1; l < n - 1; l++)
    {
        if (gcdarr[l] >= gcdarr[l - 1])
            continue;

        gcdarr[l - 1] = gcd(arr[l - 1], arr[l + 1]);
        if (l + 1 < n - 1)
            gcdarr[l] = gcdarr[l + 1];
            
        if (test(l - 1, n))
            YES;
        
        gcdarr[l - 1] = gcd(arr[l - 1], arr[l]);
        if (l + 1 < n - 1)
            gcdarr[l] = gcd(arr[l], arr[l + 1]);
    }

    for (int l = 1; l < n - 1; l++)
    {
        if (gcdarr[l] >= gcdarr[l - 1])
            continue;
        
        if (l == n - 2)
            n -= 1;
        else
        {
            gcdarr[l] = gcd(arr[l], arr[l + 2]);
            if (l < n - 2)
                gcdarr[l + 1] = gcdarr[l + 2];
        }
        if (test(l, n))
            YES;
    }

    NO;
}

int main()
{
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #endif
    int batch;
    cin >> batch;
    while (batch--)
        solve();
    return 0;
}