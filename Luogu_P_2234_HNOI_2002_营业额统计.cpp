#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, x;
set<int> s;
int sum = 0;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> x;
    sum += x;  // 第一天的最小波动值就是营业额本身
    s.insert(x);
    
    for(int i = 1; i < n; i++){
        cin >> x;
        auto it = s.lower_bound(x);
        int minDiff = LLONG_MAX;
        
        // 检查大于等于x的最小值
        if(it != s.end()){
            minDiff = min(minDiff, abs(*it - x));
        }
        
        // 检查小于x的最大值
        if(it != s.begin()){
            --it;
            minDiff = min(minDiff, abs(*it - x));
        }
        
        sum += minDiff;
        s.insert(x);
    }
    
    cout << sum << endl;
    return 0;
}