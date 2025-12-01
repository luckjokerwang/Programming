#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    int x,ans=0;
    while(n--){
        cin>>x;
        ans^=x;
    }
    cout<<ans<<endl;
    return 0;
}