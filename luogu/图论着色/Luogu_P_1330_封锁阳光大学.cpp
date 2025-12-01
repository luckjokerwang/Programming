#include <bits/stdc++.h>
using namespace std;
#define int long long
//怎么找到最短的封锁数
//成环输出impossible
//二分图染色
/*这就是典型的二分图（Bipartite Graph）定义。
我们要做的就是对图进行黑白染色
（比如 0 表示不放，1 表示放）。
算法步骤
判定合法性（染色）：

我们需要遍历每一个连通块（注意：图可能不连通）。

对于每个连通块，任选一个起点开始 DFS/BFS 染色。

如果当前点染成颜色 0，那它的邻居必须染成颜色 1；反之亦然。

冲突检测：如果在染色过程中，发现某个邻居已经被染过色，且颜色和当前点相同，说明出现了矛盾（比如存在奇环），此时直接输出 Impossible。

计算最少河蟹数：

如果染色成功（没有冲突），对于当前这个连通块，我们会得到两个颜色的数量：

cnt0: 染成颜色 0 的节点数。

cnt1: 染成颜色 1 的节点数。

我们要取最小值：min(cnt0, cnt1) 加到总答案中。（因为这一块要么全选颜色 0 的点放河蟹，要么全选颜色 1 的点，我们要选少的那个方案）。

注意：最终答案是所有连通块的最小值之和。*/

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,u,v,cnt[3];
    bool possible =true;
    cin>>n>>m;
    vector<int> color(n+1);//染色 1， 2
    vector<vector<int>> adj(n+1);
    for(int i=1;i<=m;i++){
        cin>>u>>v;//无向图
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans=0;
    function<void(int,int)> dfs=[&](int u,int c){
        color[u]=c;
        cnt[c]++;
        for(int v:adj[u]){
            if(!color[v]){
                dfs(v,3-c);
                if(!possible) return;
            }
            else{
                if(color[v]==c){
                    possible=false;
                    return;
                }
            }
        }
    };
    for(int i=1;i<=n;i++){
        if(color[i]==0){//处理连通块
            cnt[1]=cnt[2]=0;
            dfs(i,1);//遍历当前节点和它的颜色；
            if(!possible){
                cout<<"Impossible"<<endl;
                return 0;
            }
            ans+=min(cnt[1],cnt[2]);
        }
    }
    cout<<ans<<endl;
    return 0;
}