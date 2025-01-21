#include<iostream>
#include<vector>

#define NO return cout << "NO\n", void()
#define YES return cout << "YES\n", void()
using namespace std;


int n;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int now;
void solve(){
    cin>>n;
    vector<int> a(n+1),b(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //10 12 3
    //2 3

    //7
    //5 9 6 8 5 9 2

    //1 3 2 1 1 1 1

    //10
    //7 4 6 2 4 5 1 4 2 8

    //1 2 2 2 1 1 1 2 2
    now++;
    int cnt=0;
    for(int i=1;i<=n-1;i++){
        b[i]=gcd(a[i],a[i+1]);
        if(b[i-1]>b[i]){
            // if(now==7)cout<<i<<' '<<b[1]<<" "<<b[2];
            cnt++;
        }
    }
    // cout<<'\n';
    // cout<<cnt<<'\n';
    if(!cnt)YES;
    if(cnt==1&&b[1]>b[2])YES;
    if(cnt==1&&b[n-2]>b[n-1])YES;
    for(int i=2;i<=n-1;i++){
        int t=cnt;
        t-=b[i-1]>b[i];
        int cpj=gcd(a[i-1],a[i+1]);
        if(i>2){
            t-=b[i-2]>b[i-1];
            t+=cpj<b[i-2];
        }
        if(i<n-1){
            t-=b[i]>b[i+1];
            t+=cpj>b[i+1];
        }
        if(!t)YES;
    }
    NO;
}
int main(){
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