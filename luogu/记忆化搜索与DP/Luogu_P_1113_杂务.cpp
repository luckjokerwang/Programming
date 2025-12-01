#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, x, y, ans;
//记忆化搜索（dfs+缓存） 求最长路
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vector<vector<int>> v(n + 1);
    vector<int> vis(n + 1), t(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> t[i];
        while (cin >> y && y != 0)
        {
            v[y].push_back(x);
        }
    }
    function<int(int)> dfs = [&](int x) -> int
    {
        if (vis[x])
            return vis[x];
        for (int num : v[x])
        {
            vis[x] = max(vis[x], dfs(num));
        }
        vis[x] += t[x];
        return vis[x];
    };
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dfs(i));
    }
    cout << ans << endl;
    return 0;
}