#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,x,y;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    // 用标准容器声明，避免非标准的变长数组
    vector<vector<int>> v(n+1);
    vector<bool> vis(n+1, 0);

    auto dfs2 = [&](auto && self,int u)->void{
        for(auto & son : v[u])
        {
            self(self,son);
        }
    };
    dfs2(dfs2,1);
    // 递归 lambda 需要显式类型（std::function）或自传；这里用 std::function
    function<void(int)> dfs = [&](int u){
        vis[u] = 1;
        for (int num : v[u]){
            if (!vis[num]) {cout<<num<<" ";vis[num]=1;dfs(num);}
        }
    };
    for(int i=0;i<m;i++){
        cin>>x>>y;
        v[x].push_back(y);
    }
    // 邻接表升序，确保按编号小的优先访问
    for(int i=1;i<=n;i++) sort(v[i].begin(), v[i].end());
    vis[1]=1;
    cout<<1<<" ";
    dfs(1);
    cout<<endl;
    fill(vis.begin(),vis.end(),0);
    queue<int> q;
    q.push(1);
    vis[1]=1;
    cout<<1<<" ";
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int num:v[x]){
            if(!vis[num]){
                cout<<num<<" ";
                vis[num]=1;
                q.push(num);
            }
        }
    }    
    return 0;
}