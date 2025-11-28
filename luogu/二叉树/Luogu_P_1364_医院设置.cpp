#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct node{
    int father,left,right,val;
}tree[105];
bool vis[105];
int ans=1e18;
int dfs(int x,int d){
    if(!x||vis[x])return 0;
    vis[x]=1;
    return dfs(tree[x].left,d+1)+dfs(tree[x].right,d+1)+dfs(tree[x].father,d+1)+tree[x].val*d;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>tree[i].val>>tree[i].left>>tree[i].right;
        tree[tree[i].left].father=i;
        tree[tree[i].right].father=i;
    }
    for(int i=1;i<=n;i++){
        memset(vis,false,sizeof(vis));
        ans=min(ans,dfs(i,0));
    }
    cout<<ans<<endl;
    return 0;
}