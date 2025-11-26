// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// set<string> st;
// int n;
// string s;
// signed main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin>>n;
//     for(int i=0;i<n;i++){
//         cin>>s;
//         st.insert(s);
//     }
//     cout<<st.size()<<endl;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
#define base 261
#define int long long
// #define MAXN 1510
#define mod 23333
string s;
int n,ans;
vector<string> linker[mod+2];
void insert(string s){
    int hash=1;
    for(int i=0;i<s.size();i++){
        hash=(hash*base+s[i])%mod;
    }
    for(int i=0;i<linker[hash].size();i++)
        if(linker[hash][i]==s) return;
        linker[hash].push_back(s);
        ans++;
}
signed main(){
    cin>> n;
    for(int i=1;i<=n;i++){
        cin>>s;
        insert(s);
    }
    cout<<ans<<endl;
    return 0;
}