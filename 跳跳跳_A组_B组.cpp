#include <bits/stdc++.h>
using namespace std;
// 定义稍微大一点的数组，防止越界
// dp[i][j] 表示区间 [i, j] 的最大得分
// 考虑到内存限制，2000*2 = 4000, 4000*4000 的 long long 大概 128MB，是可以接受的。
// 如果内存限制很紧，需要用滚动数组优化。
long long dp[4005][4005];
int a[4005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i+n]=a[i];
    }
    int max_len=2*n;
    for(int len =1;len<=n;len++){
        for(int i=1;i<=max_len-len+1;i++){
            int j=i+len-1;//右端点
            if(len==1){
                dp[i][j]=(long long)a[i]*1;
            }
            else{
                long long pick_left=dp[i+1][j]+(long long)a[i]*len;
                long long pick_right=dp[i][j-1]+(long long)a[j]*len;
                dp[i][j]=max(pick_left,pick_right);
            }
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i][i+n-1]);
    }
    cout<<ans<<endl;
    return 0;
}
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// // 定义稍微大一点的数组，防止越界
// // dp[i][j] 表示区间 [i, j] 的最大得分
// // 考虑到内存限制，2000*2 = 4000, 4000*4000 的 long long 大概 128MB，是可以接受的。
// // 如果内存限制很紧，需要用滚动数组优化。
// long long dp[4005][4005]; 
// int a[4005];

// int main() {
//     // 优化输入输出效率
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n;
//     if (!(cin >> n)) return 0;

//     for (int i = 1; i <= n; ++i) {
//         cin >> a[i];
//         // 破环成链：复制一份到后面
//         a[i + n] = a[i];
//     }

//     // 此时数组有效范围是 1 到 2n
//     int max_len = 2 * n;

//     // 枚举区间长度 len，从 1 开始
//     for (int len = 1; len <= n; ++len) {
//         // 枚举左端点 i
//         // i 的最大值要保证 j (i + len - 1) 不超过 2n
//         for (int i = 1; i <= max_len - len + 1; ++i) {
//             int j = i + len - 1; // 右端点

//             if (len == 1) {
//                 dp[i][j] = (long long)a[i] * 1;
//             } else {
//                 // 状态转移
//                 // 1. 最后一步跳的是左端点 i，那么之前的区间是 [i+1, j]，那是第 len-1 步完成的，当前是第 len 步
//                 long long pick_left = dp[i + 1][j] + (long long)a[i] * len;
                
//                 // 2. 最后一步跳的是右端点 j，那么之前的区间是 [i, j-1]
//                 long long pick_right = dp[i][j - 1] + (long long)a[j] * len;

//                 dp[i][j] = max(pick_left, pick_right);
//             }
//         }
//     }

//     // 寻找长度为 n 的所有区间中的最大值
//     long long ans = 0;
//     for (int i = 1; i <= n; ++i) {
//         ans = max(ans, dp[i][i + n - 1]);
//     }

//     cout << ans << endl;

//     return 0;
// }