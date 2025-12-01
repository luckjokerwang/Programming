// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// string s;
// int ans;
// bool flag;
// void dfs(int n){
//     if(n==s.size()-1){
//         flag=1;
//         cout<<ans<<endl;
//         return ;
//     }
//     if(s[n+1]<=s[n]) return;
//     else{
//         ans=ans*('z'-s[n]+1)+s[n+1]-s[n];
//         dfs(n+1);
//     }
// }
// signed main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin>>s;
//     ans=s[0]-'a'+1;
//     dfs(0);
//     if(!flag) cout<<0<<endl;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
#define int long long

string s;
// 组合数数组
int C[30][30];

// 预处理组合数 (杨辉三角)
void init(){
    for(int i=0;i<=26;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> s;
    int len = s.size();
    for(int i=1;i<len;i++){
        if(s[i]<=s[i-1]){
            cout<<0<<endl;
            return 0;
        }
    }
    init();
    int ans=0;
    //加上比它位数小的数
    for(int i=1;i<len;i++){
        ans+=C[26][i];
    };
    char pre='a'-1;
    for(int i=0;i<len;i++){
        char cur=s[i];
        for(char j= pre+1;j<cur;j++){
            ans+=C['z'-j][len-1-i];
        }
        pre=cur;
    }
    cout<<ans+1<<endl;
    return 0;
}