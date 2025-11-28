#include <bits/stdc++.h>
using namespace std;
#define int long long
map<int,int> mp;
int n,c,x,ans;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>c;
    while(n--){
        cin>>x;
        mp[x]++;
    }
    for(auto [a,cnt]:mp){
        ans+=cnt*mp[a-c];//别忘了A的cnt
    }
    cout<<ans<<endl;
    return 0;
}