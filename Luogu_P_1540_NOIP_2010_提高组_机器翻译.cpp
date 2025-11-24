// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// int l,r,ans,a[1005],x,b[1005];

// signed main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int m,n;
//     cin>>m>>n;
//     for(int i=1;i<=n;i++){
//         cin>>x;
//         if(a[x]==0){
//             ans++;
//             r++;
//             b[r]=x;
//             a[x]=1;
//             if(r>m) {
//                 l++;
//                 a[b[l]]=0;
//             }
//         }
//     }
//     cout<<ans;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
queue<int> q;
bool vis[1005];
int main(){
    int m,n;
    cin>>m>>n;
    int ans=0;
    for(int i=0;i<n;i++){
            int x;
    cin>>x;
    if(!vis[x]){
        ans++;
        q.push(x);
        vis[x]=1;
    }
    if(q.size()>m){
        vis[q.front()]=0;
        q.pop();
    }
    }

    cout<<ans<<endl;
}