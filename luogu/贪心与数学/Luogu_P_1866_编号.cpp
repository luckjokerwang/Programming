#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans=1;
const int mod=1e9+7;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        ans=ans*(v[i]-i)%mod;
    }
    cout<<ans<<endl;
    return 0;
}