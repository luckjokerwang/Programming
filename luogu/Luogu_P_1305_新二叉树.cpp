#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int i;
    char val,left,right;
}tree[105];
int n;
void dfs(char x){
    if(x=='*') return;
    cout<<x;
    dfs(tree[x].left);
    dfs(tree[x].right);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>tree[i].val>>tree[tree[i].val].left>>tree[tree[i].val].right;
        tree[i].i=i;
    }
    dfs(tree[1].val);
    return 0;
}