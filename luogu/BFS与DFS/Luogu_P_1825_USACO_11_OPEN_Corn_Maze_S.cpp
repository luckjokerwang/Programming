#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> dist(n,vector<int>(m,-1));
    map<char,vector<pair<int,int>>> portals;
    queue<pair<int,int>> q;
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int dist_x,dist_y;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]>='A'&&grid[i][j]<='Z'){
                portals[grid[i][j]].push_back({i,j});
            }
            if(grid[i][j]=='@'){
                q.push({i,j});
                dist[i][j]=0;
            }
            if(grid[i][j]=='='){
                dist_x=i;
                dist_y =j;
            }
        }
    }

    while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();
        if(x==dist_x&&y==dist_y){
            cout<<dist[x][y]<<endl;
            return 0;
        }
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(grid[nx][ny]=='#') continue;
            if(dist[nx][ny]!=-1) continue;
            dist[nx][ny]=dist[x][y]+1;
            if(grid[nx][ny]>='A'&&grid[nx][ny]<='Z'){
                for(auto [n_x,n_y]:portals[grid[nx][ny]]){
                    if((n_x!=nx||n_y!=ny)&&dist[n_x][n_y]==-1){
                        q.push({n_x,n_y});
                        dist[n_x][n_y]=dist[nx][ny];
                        dist[nx][ny]+=2;
                        
                    }
                }
            }
            q.push({nx,ny});
            // if(grid[nx][ny]=='='){
            //     cout<<step<<endl;
            //     return 0;
            // }
        }
    }
    cout<<-1<<endl;
    return 0;
}