#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<vector<int>> grid;
// vector<vector<bool>> vis;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void dfs(int x,int y){
    for(int dir=0;dir<4;dir++){
        int nx=x+dx[dir];
        int ny=y+dy[dir];
       if(nx>=0&&nx<n&&ny>=0&&ny<n&&grid[nx][ny]==0){//注意这里的判断条件,不能先写grid[nx][ny]=0,因为&&是短路与
       {
           grid[nx][ny]=3;
           dfs(nx,ny);
       }
    }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    grid.resize(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0||i==n-1||j==0||j==n-1){
                if(grid[i][j]==0){
                    grid[i][j]=3;
                    dfs(i,j);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==0){
                grid[i][j]=2;
            }
            if(grid[i][j]==3){
                grid[i][j]=0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}