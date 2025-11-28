//重点题目
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;//罪犯的数目以及存在仇恨的罪犯对数
struct node{
    int a,b,c;
};
vector<node> v;
vector<int> fa,enemy;
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}

void join(int x,int y){
    int fa_x=find(x);
    int fa_y=find(y);
    if(fa_x!=fa_y)
        fa[fa_x]=fa_y;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    v.resize(m);
    fa.resize(n+1);
    enemy.resize(n+1);
    for(int i=0;i<m;i++){
        cin>>v[i].a>>v[i].b>>v[i].c;
    }
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    sort(v.begin(),v.end(),[](node a,node b){
        return a.c>b.c;
    });
    for(int i=0;i<m;i++){
        int a=v[i].a;
        int b=v[i].b;
        int c=v[i].c;
        if(find(a)==find(b)){
            cout<<c<<endl;
            return 0;
        }
        if(enemy[a]!=0){
            join(b,enemy[a]);
        }
        else{
            enemy[a]=b;
        }
        if(enemy[b]!=0){
            join(a,enemy[b]);
        }
        else{
            enemy[b]=a;
        }
    }
    cout<<0<<endl;
    return 0;
}