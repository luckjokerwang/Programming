#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    vector<int> index;
    for(int i=1;i<s.size();i++){
        if(s[i]==s[i-1]+1){
            index.push_back(i);
        }
    }
    int ans=0;
    for(int n: index){
        int num=1;
        while(n-num-1>=0&&n+num<s.size()&&s[n-num-1]==s[n-1]&&s[n+num]==s[n]){
            num++;
        }
        ans+=num;
    }
    cout<<ans<<endl;
    return 0;
}