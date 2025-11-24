#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[15];
vector<int> prime[15];
vector<bool> vis(1005);
int min_ans=-1;
void dfs(int step,int sum){
    if(min_ans!=-1&&sum>=min_ans) return;//剪枝
    if(step==n){
        if(min_ans==-1||min_ans>sum) min_ans=sum;
        return;
    }
    for(int p:prime[step]){
        if(vis[p]) continue;
        vis[p]=true;
        dfs(step+1,sum+p);
        vis[p]=false;
    }
}
void get_prime(int idx,int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            prime[idx].push_back(i);
            while(x%i==0) x/=i;
        }
    }
    if(x>1) prime[idx].push_back(x);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        get_prime(i,a[i]);
    }
    dfs(0,0);
    cout<<min_ans<<endl;
    return 0;
}