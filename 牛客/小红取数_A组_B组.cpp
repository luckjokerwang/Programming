#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<int> dp(k,-1);
    dp[0]=0;
    for(int num:v){
        vector<int> new_dp=dp;
        for(int j=0;j<k;j++){
            if(dp[j]!=-1){
                int new_mod=(j+num)%k;
                int new_sum=dp[j]+num;
                new_dp[new_mod]=max(new_dp[new_mod],new_sum);
        }
        }
        dp=new_dp;
    }
    
    // // dp[i] 表示和模k余i时的最大和，-1表示不可达
    // vector<int> dp(k, -1);
    // dp[0] = 0; // 初始状态：什么都不取，和为0，余数为0
    
    // for(int i = 0; i < n; i++){
    //     vector<int> new_dp = dp; // 复制当前状态
    //     for(int j = 0; j < k; j++){
    //         if(dp[j] != -1){ // 如果状态j可达
    //             int new_mod = (j + v[i]) % k;
    //             int new_sum = dp[j] + v[i];
    //             new_dp[new_mod] = max(new_dp[new_mod], new_sum);
    //         }
    //     }
    //     dp = new_dp;
    // }
    
    cout << dp[0] << endl;
    return 0;
    
}