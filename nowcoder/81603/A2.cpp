#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll ans;

void solve(){
    ll n;
    map<ll,vector<int>>mp;
    map<ll,bool>m;
    cin>>n;
    vector<ll>a(n+1);
    set<vector<int>>s,m1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        m[a[i]]=1;
        for(int j=1;j*j<=a[i];j++){
            if(a[i]%j==0){
                if(a[i]/j!=j)mp[a[i]/j].push_back(a[i]);
                mp[j].push_back(a[i]);
            }
        }
    }
    for(auto it=mp.rbegin();it!=mp.rend();it++){
        sort(it->second.begin(),it->second.end());
        if(m1.count(it->second))it->second.clear();
        m1.insert(it->second);
    }
    for(auto [x,v]:mp){
        if(m.count(x))continue;
        if(v.size()>=2)s.insert(v);
    }
    if(s.size()&1)cout<<"dXqwq\n";
    else cout<<"Haitang\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
//n=S(m)+x*m