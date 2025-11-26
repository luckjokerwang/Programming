#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,u,v,x,y;
struct node{
    int left,right,parent;
}tree[105];
int dfs(int x){
    if(!x) return 0;
    return max(dfs(tree[x].left),dfs(tree[x].right))+1; 
}
bool vis[105];
void dfs_dist(int u,int dist){
    vis[u]=1;
    if(u==v) {
        cout<<dist<<endl;
        return ;}
     if(!vis[tree[u].left]&&tree[u].left) dfs_dist(tree[u].left,dist+1);
     if(!vis[tree[u].right]&&tree[u].right) dfs_dist(tree[u].right,dist+1);
     if(!vis[tree[u].parent]&&tree[u].parent) dfs_dist(tree[u].parent,dist+2);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        tree[v].parent=u;
        if(tree[u].left==0) tree[u].left=v;
        else tree[u].right=v;
    }
    cin>>u>>v;
    cout<<dfs(1)<<endl;
    queue<int> q;
    q.push(1);
    int depth=0;
    while(!q.empty()){
        int size=q.size();
        depth=max(depth,size);
        for(int i=0;i<size;i++){
            int cur=q.front();
            q.pop();
            if(tree[cur].left) q.push(tree[cur].left);
            if(tree[cur].right) q.push(tree[cur].right);
        }
    }
    cout<<depth<<endl;
    dfs_dist(u,0);
    return 0;
}