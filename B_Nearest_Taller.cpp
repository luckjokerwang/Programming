#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            if(a[i]<a[j]){
                cout<<j<<endl;
                break;
            }
            if(j==1){
                cout<<-1<<endl;
            }
        }
    }
    // vector<pair<int,int>> a(n+1);
    // for(int i=1;i<=n;i++){
    //     cin>>a[i].second;
    //     a[i].first=i;
    // }
    // sort(a.begin()+1,a.end(),[](pair<int,int >&x,pair<int,int>&y){//val从大到小排，如果相等index从小到大排
    //     return x.second!=y.second?x.second>y.second:x.first<y.first;
    // });
    // vector<int> ans(n+1,-1);
    // // ans[a[1].first]=-1;
    // for(int i=2;i<=n;i++){
    //     // if(a[i].second==a[i-1].second) continue;
    //     int temp=1;
    //     while((a[i].first<a[i-temp].first&&i-temp>=1)||a[i].second==a[i-temp].second){
    //         temp++;
    //     }
    //     if(i-temp!=0&&a[i].first>a[i-temp].first){
    //         ans[a[i].first]=a[i-temp].first;
    // }
    // }
    // for(int i=1;i<=n;i++){
    //     cout<<ans[i]<<endl;
    // }
    //     return 0;
    // vector<int> a(n+1);
    // for(int i=1;i<=n;i++){
    //     cin>>a[i];
    // }
    // sort(a.begin()+1,a.end());

}