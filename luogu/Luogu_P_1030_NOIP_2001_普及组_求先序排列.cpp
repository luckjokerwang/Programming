#include <bits/stdc++.h>
using namespace std;
#define int long long
string s1,s2;
void dfs(int l1,int r1,int l2,int r2){
    if(l1>r1||l2>r2) return;
    cout<<s2[r2];
    int idx=s1.find(s2[r2]);//idx=top在s1中的位置
    int dist=idx-l1;//计算s1中top左边的长度
    dfs(l1,idx-1,l2,l2+dist-1);//遍历左节点
    dfs(idx+1,r1,l2+dist,r2-1);//遍历右节点
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s1>>s2;
    int right=s1.size()-1;
    dfs(0,right,0,right);
    return 0;
}