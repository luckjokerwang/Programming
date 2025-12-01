#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,u,v,ans;
int mod=80112002;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    vector<int> ind(n+1),outd(n+1),f(n+1);//初度，入度和数量
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        ind[v]++;
        outd[u]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(ind[i]==0){
            q.push(i);
            f[i]=1;
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:adj[u]){
            ind[v]--;
            f[v]=(f[v]+f[u])%mod;
            if(ind[v]==0){
                q.push(v);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(outd[i]==0){
            ans=(ans+f[i])%mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}