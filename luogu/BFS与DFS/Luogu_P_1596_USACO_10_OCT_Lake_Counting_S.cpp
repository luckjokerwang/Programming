#include <bits/stdc++.h>
using namespace std;
#define int long long
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int n,m;
queue<pair<int,int>> q;
vector<vector<char>> grid;
vector<vector<bool>> vis;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    grid.resize(n,vector<char>(m));
    vis.resize(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int lake_count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='W'&&!vis[i][j]){
                lake_count++;
                vis[i][j]=true;
                q.push({i,j});
                while(!q.empty()){
                    auto [x,y]=q.front();
                    q.pop();
                    for(int dir=0;dir<8;dir++){
                        int nx=x+dx[dir];
                        int ny=y+dy[dir];
                        if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]=='W'&&!vis[nx][ny]){
                            vis[nx][ny]=true;
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
    }
    cout<<lake_count<<endl;
    return 0;
}