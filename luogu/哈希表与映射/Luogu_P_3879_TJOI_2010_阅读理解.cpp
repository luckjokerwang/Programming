#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,l,m;
string s;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    unordered_set<string> st[n+1];
    for(int i=1;i<=n;i++){
        cin>>l;
        while(l--){
            cin>>s;
            st[i].insert(s);
        }
    }
    cin>>m;
    while(m--){
        cin>>s;
        for(int i=0;i<=n;i++){
            if(st[i].count(s)){
               cout<<i<<" "; 
            }
        }
        cout<<endl;
    }
    return 0;
}