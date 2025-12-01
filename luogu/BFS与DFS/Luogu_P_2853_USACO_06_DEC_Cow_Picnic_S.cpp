// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// int k,n,m,x,u,v,ans,cnt;
// unordered_map<int,bool> mp;
// signed main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin>>k>>n>>m;
//     for(int i=0;i<k;i++) {
//         cin>>x;
//         mp[x]=false;
//     }
//     vector<vector<int>> adj(n+1);
//     for(int i=0;i<n;i++){
//         cin>>u>>v;
//         adj[u].push_back(v);
//     }
//     for(int i=1;i<=n;i++){
//         sort(adj[i].begin(),adj[i].end());
//         adj[i].erase(unique(adj[i].begin(),adj[i].end()),adj[i].end());
//     }
//     function<void(int)> dfs=[&](int x){
//         if(mp.count(x)&&mp[x]==false){
//             mp[x]=true;
//             cnt++;
//         }
//         if(cnt==k){
//             ans++;
//             cnt=0;
//             return;
//         }
//         for(int v:adj[x]){
//             dfs(v);
//         }
//     };
//     for(int i=1;i<=n;i++){
//         // fill(mp.begin(),mp.end(),false)；
//         // 这种方法保留 Key，只把 Value 归零
//     for (auto& it : mp) {
//     it.second = false; // 或者 0
//     }
//         dfs(i);
//     }
//     cout<<ans<<endl;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
/*思路：看数据量，奶牛最少
1.将奶牛所在的牧场dfs遍历，能到达的就加一 ：vis，cnt++
2.如果牧场的cnt==奶牛量 ans++
*/
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k,n,m,u,v;
    cin>>k>>n>>m;
    vector<int> cows(k+1),vis(n+1),cnt(n+1);
    vector<vector<int>> adj(n+1);
    for(int i=1;i<=k;i++){
        cin>>cows[i];
    }
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
    }
    function<void(int)> dfs=[&](int num){
        vis[num]=true;
        cnt[num]++;
        for(int v:adj[num]){
            if(!vis[v])
            dfs(v);
        }
    };
    for(int num:cows){//不严谨
        fill(vis.begin(), vis.end(), 0);  // ✅ 正确：用 fill 清空 vector
        dfs(num);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(cnt[i]==k){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}