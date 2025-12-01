#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,u,v,value,ans=-1e18;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    vector<int> p(n+1,-1e18);
    for(int i=0;i<m;i++){
        cin>>u>>v>>value;
        adj[u].push_back({v,value});
    }
    function<int(int)> dfs=[&](int x)->int{
        if(x==n) return 0; 
        if(p[x]!=-1e18) return p[x];
        for(auto[v,value]:adj[x]){
            int res = dfs(v);
            
            // 【关键修改点 1】
            // 只有当 v 能到达 n (res != -INF) 时，这条路才有效
            if (res != -1e18) {
                // 注意：这里要处理 p[x] 还是 -INF 的情况
                if (p[x] == -1e18) {
                    p[x] = res + value;
                } else {
                    p[x] = max(p[x], res + value);
                }
            }
            // p[x]=max(p[x],dfs(v)+value);
        }
        return p[x];
    };
    ans=dfs(1);
    if(ans==-1e18) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long

// const int INF = 1e18; // 用一个极大值表示无穷
// int n, m, u, v, value;

// // memo 数组用来存结果，vis 数组用来判断是否计算过
// int memo[1505];
// bool vis[1505]; 

// vector<pair<int,int>> adj[1505];

// int dfs(int x) {
//     // 【修正1】Base Case：只有到达 n 才返回 0，表示路径结束且合法
//     if (x == n) return 0;
    
//     // 【修正2】使用 vis 数组判断，防止 0 权路径重复计算
//     if (vis[x]) return memo[x];

//     int max_dist = -INF; // 【修正3】初始化为负无穷，表示当前点 x 无法到达 n

//     for (auto [v, w] : adj[x]) {
//         int res = dfs(v);
//         // 只有当 v 能到达 n (res != -INF) 时，才更新路径
//         if (res != -INF) {
//             max_dist = max(max_dist, res + w);
//         }
//     }

//     vis[x] = true;
//     return memo[x] = max_dist;
// }

// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
    
//     cin >> n >> m;
//     for (int i = 0; i < m; i++) {
//         cin >> u >> v >> value;
//         // 题目保证 u < v，无环，所以可以直接存图
//         adj[u].push_back({v, value});
//     }

//     // 不需要循环 1 到 n，只需要求 dfs(1)
//     int ans = dfs(1);

//     // 如果 ans 还是初始的负无穷，说明 1 无法到达 n
//     if (ans == -INF) {
//         cout << -1 << endl;
//     } else {
//         cout << ans << endl;
//     }

//     return 0;
// }