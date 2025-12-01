#include <bits/stdc++.h>
using namespace std;
/*思路：遍历每个单位迷宫所有能到达的地方
如果首尾能到达，就yes，否则no，思路错了
*/
int n,m,x,y;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool flag=0;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin>>n>>m){
        flag=0;
        vector<vector<char>> grid(n,vector<char>(m));
        vector<vector<bool>> vis(n,vector<bool>(m));
// 新增：用来记录第一次到达该点时的"真实坐标"
        vector<vector<int>> val_x(n,vector<int>(m));
        vector<vector<int>> val_y(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
                if(grid[i][j]=='S'){
                    x=i;
                    y=j;
                    // cout<<x<<" "<<y<<endl;
                }
            }
        }
            function<void(int,int)> dfs=[&](int x,int y){
            if(flag) return; // 如果已经找到答案，快速退出

            // 计算在原地图中的映射坐标 (处理负数取模)
            int mx = (x % n + n) % n;
            int my = (y % m + m) % m;
            
            // 撞墙处理
            if(grid[mx][my] == '#') return;

            // 核心逻辑：如果这个点(映射后)来过
            if(vis[mx][my]){
                // 如果之前的真实坐标和现在的真实坐标不一样 -> 说明穿越了 -> Yes
                if(val_x[mx][my] != x || val_y[mx][my] != y){
                    flag = 1;
                }
                return;
            }

            // 记录状态
            vis[mx][my] = 1;
            val_x[mx][my] = x;
            val_y[mx][my] = y;

            for(int i=0;i<4;i++){
                int nx=dx[i]+x;
                int ny=dy[i]+y;
                // 删除了这里的边界判断(nx>=n...)，允许坐标无限延伸
                dfs(nx,ny);
            }
        };
        
        dfs(x,y);
        
        // 删除了原先的for循环判断，直接看flag
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}