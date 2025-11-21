#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
const int MAXN=1005;
char grid[MAXN][MAXN];
int ans[MAXN][MAXN];
bool vistied[MAXN][MAXN];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int n,m;
void bfs(int sx,int sy){
    vector<pair<int,int>> component;
    queue<pair<int,int>> q;
    q.push({sx,sy});
    
    
    vistied[sx][sy]=true;
    component.push_back({sx,sy});
    int count=0;
    while(!q.empty()){
        pair<int,int> curr =q.front();
        q.pop();
        count++;
        for(int i=0;i<4;i++){
            int ny=curr.second+dy[i];
            int nx=curr.first+dx[i];
        if(nx>=0&&nx<n&&ny>=0&&ny<n){
            if(!vistied[nx][ny]&&grid[nx][ny]!=grid[curr.first][curr.second]){
                vistied[nx][ny]=true;
                q.push({nx,ny});
                component.push_back({nx,ny});
            }
        }
        }
    }
    for(auto p:component){
        ans[p.first][p.second]=count;
    }
    
}
int main(){
    cin>>n>>m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!vistied[i][j]){
                bfs(i,j);
            }
        }
    }

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        cout<<ans[x-1][y-1]<<endl;

    }
    return 0;
}
// #include <iostream>
// #include <vector>
// #include <string>
// #include <queue>

// using namespace std;

// const int MAXN = 1005;
// int n, m;
// char grid[MAXN][MAXN];      // 用 char 数组存图
// int ans[MAXN][MAXN];        // 记录每个点对应的连通块大小
// bool visited[MAXN][MAXN];   // 记录是否访问过

// // 方向数组
// int dx[4] = {1, -1, 0, 0};
// int dy[4] = {0, 0, 1, -1};

// // 结构体方便存坐标
// struct Point {
//     int x, y;
// };

// void bfs(int sx, int sy) {
//     vector<Point> component; // 暂存属于当前连通块的所有点
//     queue<Point> q;
    
//     q.push({sx, sy});
//     visited[sx][sy] = true;
//     component.push_back({sx, sy});
    
//     int count = 0; // 当前连通块的大小
    
//     while (!q.empty()) {
//         Point curr = q.front();
//         q.pop();
//         count++;
        
//         for (int i = 0; i < 4; i++) {
//             int nx = curr.x + dx[i];
//             int ny = curr.y + dy[i];
            
//             // 边界检查
//             if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
//                 // 如果没访问过，且颜色不同（0->1 或 1->0）
//                 if (!visited[nx][ny] && grid[nx][ny] != grid[curr.x][curr.y]) {
//                     visited[nx][ny] = true;
//                     q.push({nx, ny});
//                     component.push_back({nx, ny}); // 记录这个点属于当前块
//                 }
//             }
//         }
//     }
    
//     // 关键步骤：把算出来的 count 赋值给刚才找到的所有点
//     // 这样以后查询其中任何一个点，都不用再算了
//     for (auto p : component) {
//         ans[p.x][p.y] = count;
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     cin >> n >> m;
    
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             cin >> grid[i][j];
//         }
//     }
    
//     // 预处理：遍历所有点，如果没访问过，就跑一次 BFS 算出连通块
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if (!visited[i][j]) {
//                 bfs(i, j);
//             }
//         }
//     }
    
//     // 回答询问
//     for (int i = 0; i < m; i++) { // 注意这里是 m
//         int x, y;
//         cin >> x >> y;
//         // 题目坐标从1开始，我们要减1
//         cout << ans[x-1][y-1] << endl;
//     }
    
//     return 0;
// }
