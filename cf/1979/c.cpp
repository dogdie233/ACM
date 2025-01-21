#include <iostream>
#include <vector>
using namespace std;
using ll =long long;
const int N = 1e5 + 5;
int a[N],b[N];
int gcd(int a,int b){
    return a%b==0?b:gcd(b,a%b);
}
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
inline void solve()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    int LCM=1;
    for(int i=0;i<n;i++){
        LCM=lcm(LCM,a[i]);
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=LCM/a[i];
        b[i]=LCM/a[i];
    }
    if(sum>=LCM){
        cout<<"-1\n";
        return;
    }
    else {
        for(int i=0;i<n;i++)
            cout<<b[i]<<" \n"[i==n-1];
    }
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