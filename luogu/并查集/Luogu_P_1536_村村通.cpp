#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,u,v,cnt;
int fa[1005],vis[1005];//存祖宗
int find(int u){
    if(u==fa[u]) return u;
    return fa[u]=find(fa[u]);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin>>n && n!=0){
        cin>>m;
        cnt=0;
        for(int i=1;i<=n;i++){
            fa[i]=i;
            vis[i]=0;
        }
        for(int i=0;i<m;i++){
            cin>>u>>v;
            // if(find(u)!=find(v))
            //     fa[u]=v; 完全错误
            int fu=find(u);
            int fv=find(v);
            if(fu!=fv){
                fa[fu]=fv;
            }
        }
        for(int i=1;i<=n;i++){
            if(!vis[find(i)]){
                cnt++;
                vis[find(i)]=1;
            }
        }
        cout<<cnt-1<<endl;
    }
    
    return 0;
}