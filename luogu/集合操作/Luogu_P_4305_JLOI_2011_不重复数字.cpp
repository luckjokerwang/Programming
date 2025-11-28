#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
vector<int> v;
unordered_set<int> seen;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        v.resize(n);
        seen.clear();
        for(int i=0;i<n;i++) cin>>v[i];
        for(int num:v){
            if(!seen.count(num)){
                cout<<num<<" ";
                seen.insert(num);
            }
        }
        cout<<endl;
    }
    return 0;
}