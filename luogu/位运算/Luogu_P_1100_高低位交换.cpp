#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    string s,s1,s2;
    while(n){
        s+=(n%2)+'0';
        n/=2;
    }
    while(s.size()<32){
        s+='0';
    }
    reverse(s.begin(),s.end());
    s1=s.substr(0,16);
    s2=s.substr(16,16);
    s=s2+s1;
    int ans=0;
    for(int i=0;i<32;i++){
        ans=2*ans+s[i]-'0';
    }
    cout<<ans<<endl;
    return 0;
}