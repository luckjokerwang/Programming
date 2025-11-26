#include <bits/stdc++.h>
using namespace std;
#define int long long
string s1,s2;
void dfs(int l1,int r1,int l2,int r2){
    if(l1>r1||l2>r2) return;
    int idx=s1.find(s2[l2]);//找到根节点,分割
    int dis=idx-l1;
    dfs(l1,idx-1,l2+1,l2+dis);//遍历左节点
    dfs(idx+1,r1,l2+dis+1,r2);//遍历右节点
    cout<<s2[l2];
}
signed main(){
    cin>>s1>>s2;
    int right=s1.size()-1;
    dfs(0,right,0,right);
    return 0;
}