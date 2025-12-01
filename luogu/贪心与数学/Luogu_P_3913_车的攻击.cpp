#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_set<int> st1,st2;//存x轴和y轴
int n,k,x,y;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>x>>y;
        st1.insert(x);
        st2.insert(y);
    }
    int ans=(st1.size()+st2.size())*n-st1.size()*st2.size();
    cout<<ans<<endl;
    return 0;
}