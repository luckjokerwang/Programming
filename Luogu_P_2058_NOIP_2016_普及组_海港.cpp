#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int cnt[100005], t, k;
int ans;
queue<pair<int, int>> q;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            // if (x < 0 || x >= 10005) continue; // 检查x的范围
            cnt[x]++;
            q.push({t, x});
            if (cnt[x] == 1) ans++;
        }
        
        while (!q.empty() && t - q.front().first >= 86400) {
            int h_x = q.front().second;
            cnt[h_x]--;
            if (cnt[h_x] == 0) ans--;
            q.pop();
        }
        
        cout << ans << endl;
    }
    return 0;
}