// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// int n, m;

// // 预计算每个数的位数
// vector<int> digits;

// // 计算 f(a, b) % m
// int concat_mod(int a, int b, int idx_b)
// {
//     int result = a % m;
//     // 将 a 左移 b 的位数,然后加上 b
//     for (int i = 0; i < digits[idx_b]; i++)
//     {
//         result = (result * 10) % m;
//     }
//     result = (result + b % m) % m;
//     return result;
// }

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n >> m;
//     vector<int> v(n);
//     digits.resize(n);

//     for (int i = 0; i < n; i++)
//     {
//         cin >> v[i];
//         // 计算位数
//         int x = v[i], d = 0;
//         if (x == 0)
//             d = 1;
//         else
//             while (x)
//             {
//                 d++;
//                 x /= 10;
//             }
//         digits[i] = d;
//     }

//     int cnt = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (concat_mod(v[i], v[j], j) == 0)
//             {
//                 cnt++;
//             }
//         }
//     }
//     cout << cnt << "\n";
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
vector<int> v(n);   
map<int,map<int,int>> group;
for(int i=0;i<n;i++){
    cin>>v[i];
    int d=to_string(v[i]).size();
    int mod=v[i]%m;
    group[d][mod]++;
}
//f(a,b)=(a*10^d+b)
/*f(a,b)%m=0 -> (a*10^d)%m + b%m = 0
-> (a*10^d)%m = (m - b%m)%m
所有求(m-b%m)%m的组合数之和即为答案
所以求解题思路为:
1. 预处理每个数字的位数d和模m的结果mod，并统计每种(d, mod)组合的出现次数。
2. 对于每个数字a，计算其模m结果b_mod = a % m。
3. 对于每个位数d，计算需要的模值needed_mod = (m - b_mod) % m。
*/ 
int cnt =0;
for(int i=0;i<n;i++){
    int ai_mod = v[i]%m;
    for(auto&[d,mp]:group){
        int pow10=1;
        for(int k=0;k<d;k++){
            pow10=(pow10*10)%m;
        }
        int need=(m-(ai_mod*pow10)%m)%m;
        if(mp.count(need))
            cnt += mp[need];
    }
}
cout<<cnt<<"\n";
    return 0;
}