// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// bool dp[30][400];

// signed main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int n;
//     cin>>n;
//     dp[0][0]=true;
//     for(int i=1;i<=n;i++){
//         for(int r=1;r<=i;r++){
//             int rem=i-r;
//         }
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;

// // dp[i][j] 表示 i 条直线是否有可能是 j 个交点
// // N <= 25, 最大交点数约为 300，开 400 足够
// bool dp[30][400]; 

// int main() {
//     int n;
//     cin >> n;

//     // 初始化：0 条直线的交点数肯定是 0
//     dp[0][0] = true;

//     // i 代表当前总共有多少条直线
//     for (int i = 1; i <= n; ++i) {
//         // r 代表我们要剥离出来的“互相平行的直线”的数量
//         // 这一组 r 条直线之间没有交点，但会和剩下的 i-r 条直线产生交点
//         for (int r = 1; r <= i; ++r) {
//             int rem = i - r; // 剩下的直线数量 (remainder)
            
//             // 剩下的 rem 条直线，最多能产生 rem*(rem-1)/2 个交点
//             // 我们遍历所有可能的子问题交点数 k
//             int max_rem_intersections = (rem * (rem - 1)) / 2;
            
//             for (int k = 0; k <= max_rem_intersections; ++k) {
//                 // 如果子问题 (rem 条直线产生 k 个交点) 是成立的
//                 if (dp[rem][k]) {
//                     // 计算当前的总交点数
//                     // 公式：子问题交点 + (平行线数量 * 剩余线数量)
//                     int current_intersections = k + r * rem;
                    
//                     // 标记状态为可行
//                     dp[i][current_intersections] = true;
//                 }
//             }
//         }
//     }

//     // 统计 N 条直线所有可能的方案
//     int ans = 0;
//     int max_possible = (n * (n - 1)) / 2;
//     for (int j = 0; j <= max_possible; ++j) {
//         if (dp[n][j]) {
//             ans++;
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
bool has_ans[1005];
int n,ans;
void dfs(int left,int sum_q,int min_val){
    if(left==0){
        int sum=(n*n-sum_q)/2;
        if(!has_ans[sum]){
            has_ans[sum]=true;
            ans++;
        }
    }
    for(int i=min_val;i<=left;i++){
        dfs(left-i,sum_q+i*i,i);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    dfs(n,0,1);
    cout<<ans<<endl;
}