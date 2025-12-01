#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
const int MAXN=1000005;
int cnt[MAXN],w[MAXN];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        cnt[v[i]]++;
    }
    for(int i=1;i<=MAXN;i++){
        for(int j=i;j<=MAXN;j+=i){
            w[j]+=cnt[i];
        }
    }
    for(int num:v){
        cout<<w[num]-1<<endl;
    }
    return 0;
}