//方法一：并查集➕到根节点的距离
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// int n,v;
// int ans=1e18;
// signed main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin>>n;
//     vector<int> fa(n+1),d(n+1);
//     for(int i=1;i<=n;i++){
//         fa[i]=i;
//     }
//     function<int(int)> find=[&](int x){
//         if(x==fa[x]) return x;
//         int root=find(fa[x]);// 先递归存下根，顺便让递归过程把 d[fa[x]] 更新好
//         d[x]+=d[fa[x]];// 此时 d[fa[x]] 已经是正确的值了，加给 d[x]
//         return fa[x]=root;// 最后路径压缩
//     };
//     for(int i=1;i<=n;i++){
//         cin>>v;
//         int fx=find(i);
//         int fy=find(v);
//         if(fx!=fy){
//             fa[fx]=fy;
//             // 因为 find(i) 后，i 直接指向 root_i，距离是 d[i]
//             d[fx]=d[v]+1;
//         }
//         else{
//             ans=min(ans,d[v]+1);
//         }
//     }
//     cout<<ans<<endl;
//     return 0;
// }
//法二：dfs
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,v;
int ans=1e18;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    vector<int> to(n+1),step(n+1);
    vector<int> vis(n+1);
    for(int i=1;i<=n;i++){
        cin>>v;
        to[i]=v;
    }
    function<void(int,int)> dfs=[&](int u,int cur_step){
        vis[u]=1;
        step[u]=cur_step;
        int v=to[u];
        if(!vis[v]){
            dfs(v,cur_step+1);
        }
        else if(vis[v]==1){
            int cycle_len=cur_step-step[v]+1;
            ans=min(ans,cycle_len);
        }
        vis[u]=2;
    };
    for(int i=1;i<=n;i++){
        if(!vis[i])
            dfs(i,1);
    }
    cout<<ans<<endl;
    return 0;
}