#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
using ll =long long;

vector<int>E[45];

int vis[46];
int ans;
void dfs(int fa,int now, int num){
    bool f = true;
    for (auto to : E[now])
    {
        if (!vis[to])
        {
            f = 0;
            break;
        }
    }
    if (f)
    {
        ans=max(ans,num);
        return;
    }
    for(auto to:E[now])
        vis[to] += 1;
    for(auto to:E[now]){
        if(to != fa && vis[to] < 2)
            dfs(now,to,num+1);
    }
    for(auto to : E[now])
        vis[to] -= 1;
}
void solve(){
    int n,m;
    cin>>n>>m;
    if(n==1)ans=1;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        vis[i]=1;
        dfs(0,i,1); 
    }
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
   // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}