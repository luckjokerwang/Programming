#include <bits/stdc++.h>
using namespace std;
#define int long long
//树的完美匹配和 二分图染色
/*思路:两个dfs,一个找到match对,一个染色
,如果第一个没有匹配,就直接possible=false停掉
*/
const int MAXN=1e5+5;
vector<int> adj[MAXN];
int match[MAXN];
char color[MAXN];
int n;
bool possible =true;
void dfs_match(int u,int p){
    for(int v:adj[u]){
        if(v==p) continue;
        dfs_match(v,u);
        if(!possible) return;//早到之后就提前结束
        if(match[v]==0){//如果子节点有了,进入下一个dfs,否则看父节点
            if(match[u]==0){//如果父节点也落单,刚好一对苦命鸳鸯,否则死翘翘
            match[v]=u;
            match[u]=v;
        }
         else{
            possible=false;
            return;
        }
        }
       
    }
}
void dfs_color(int u,char c){
    if(color[u]!=0) return;//防御性编程,没有也行
    int partner =match[u];
    color[u]=c;
    color[partner]=c;
    char next_c=(c=='R'?'B':'R');
    for(int v:adj[u]){
        if(v!=partner&&color[v]==0)
        dfs_color(v,next_c);
    }
    for(int v:adj[partner]){
        if(v!=u&&color[v]==0)
        dfs_color(v,next_c);
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //寻找匹配
    if(n%2!=0){
        cout<<-1<<endl;
        return 0;
    }
    dfs_match(1,0);
    if(!possible){
        cout<<-1<<endl;
        return 0;
    }
    //染色
    dfs_color(1,'R');
    for(int i=1;i<=n;i++){
        cout<<color[i];
    }
    cout<<endl;
    return 0;
}