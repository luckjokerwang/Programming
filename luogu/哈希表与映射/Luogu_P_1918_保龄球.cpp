#include <bits/stdc++.h>
using namespace std;
#define int long long
map<int,int> mp;
int n,x,q,m;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        mp[x]=i;
    }
    cin>>q;
    while(q--){
        cin>>m;
        cout<<mp[m]<<endl;
    }
    return 0;
}