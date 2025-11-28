#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,p,q,ans;
char opt;
vector<int> fa,enemy;
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void join(int x,int y){
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy){
        fa[fx]=fy;//father变成fy
        // cnt[fy]+=cnt[fx];
        ans--;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    fa.resize(n+1);
    enemy.resize(n+1);
    ans=n;
    // cnt.resize(n+1);
    for(int i=1;i<=n;i++) {
        fa[i]=i;
        // cnt[i]=1;
    }
    while(m--){
        cin>>opt>>p>>q;
        if(opt=='F'){
            join(p,q);
        }
        if(opt=='E'){
            if(enemy[p]!=0){
                join(q,enemy[p]);
            }
            else{
                enemy[p]=q;
            }
            if(enemy[q]!=0){
                join(p,enemy[q]);
            }
            else{
                enemy[q]=p;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}