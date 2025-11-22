#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;

// 预计算每个数的位数
vector<int> digits;

// 计算 f(a, b) % m
int concat_mod(int a, int b, int idx_b) {
    int result = a % m;
    // 将 a 左移 b 的位数,然后加上 b
    for(int i = 0; i < digits[idx_b]; i++) {
        result = (result * 10) % m;
    }
    result = (result + b % m) % m;
    return result;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    vector<int> v(n);
    digits.resize(n);
    
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        // 计算位数
        int x = v[i], d = 0;
        if(x == 0) d = 1;
        else while(x) { d++; x /= 10; }
        digits[i] = d;
    }
    
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(concat_mod(v[i], v[j], j) == 0) {
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}