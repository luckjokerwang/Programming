#include <bits/stdc++.h>
using namespace std;
int n,m,k,x,y,q;
string s;
char c;
int main(){
    cin>>n>>m>>k;
    vector<vector<int>> grid(n,vector<int>(m));//地图
    vector<int> cnt(k+1);
    vector<pair<int,int>> pos(k+1);//位置
    map<string,int> mp;//name->int
    map<int,string> rmp;//idx->name
    for(int i=0;i<k;i++){
        cin>>s>>x>>y;
        mp[s]=i;
        rmp[i]=s;
        cnt[i]=1;
        grid[x][y]=i;
        pos[i].first=x;
        pos[i].second=y;
    }
    map<char,pair<int,int>> dis;//x,y
    dis['D']={1,0};
    dis['W']={0,1};
    dis['S']={0,-1};
    dis['A']={-1,0};
    cin>>q;
    while(q--){
        cin>>s>>c;
        int idx=mp[s];
        int dx=dis[c].first;//移动方位
        int dy=dis[c].second;
        int nx=pos[idx].first+dx;//现在位置
        int ny=pos[idx].second+dy;
        if(nx<0||nx>=n||ny<0||ny>=m){
            cout<<"out of bounds!"<<endl;
        }
        else if(grid[nx][ny]==0){
            pos[idx].first=nx;
            pos[idx].second=ny;
            cnt[idx]++;
            grid[nx][ny]=idx;
            cout<<"vanquish!"<<endl;
        }
        else if(grid[nx][ny]==idx){
            pos[idx].first=nx;
            pos[idx].second=ny;
            cout<<"peaceful."<<endl;
        }
        else if(grid[nx][ny]!=idx){
            int idx2=grid[nx][ny];
            if(cnt[idx]>cnt[idx2]){
                cout<<endl;
            }
        }  
    }
}