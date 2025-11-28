// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// int t, n, i, j, e, flag;
// //存在的问题：未输入就初始化
// /* i,j比n大多了，需要离散化处理
// 应该先处理🟰，再处理！=，不然有可能被钻漏洞
// 离散化：一个原始去重,用vector+sort+unique，set找不到坐标
// 在用一个数组存vector中数的坐标
// */
// vector<int> fa;
// int find(int x)
// {
//     if (x == fa[x])
//         return x;
//     return fa[x] = find(fa[x]);
// }
// void join(int x, int y)
// {
//     int fx = find(x);
//     int fy = find(y);
//     if (fx != fy)
//         fa[fx] = fy;
// }
// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> t;
//     while (t--)
//     {
//         flag = 1;
//         cin >> n;
//         fa.resize(n + 1);
//         for (int i = 1; i < n; i++)
//         {
//             fa[i] = i;
//         }
//         while (n--)
//         {
//             cin >> i >> j >> e;
//             if (e == 1)
//             {
//                 join(i, j);
//             }
//             else
//             {
//                 if (find(i) == find(j))
//                     flag = 0;
//             }
//         }
//         if (flag)
//             cout << "YES" << endl;
//         else
//             cout << "NO" << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5;
struct node
{
    int x, y, e;
} q[MAXN];
int t, n, fa[MAXN],flag;
vector<int> nums;
int get_id(int x)
{
    return lower_bound(nums.begin(),nums.end(),x)-nums.begin();
}
int find(int x){
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
void join(int x,int y){
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy){
        fa[fx]=fy;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        flag=1;
        nums.clear();
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> q[i].x >> q[i].y >> q[i].e;
            nums.push_back(q[i].x);
            nums.push_back(q[i].y);
        }
        // 离散化
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            fa[i] = i;
        }
        sort(q, q + n, [](node a, node b)
             { return a.e > b.e; });
        for (int i = 0; i < n; i++)
        {
                int x = get_id(q[i].x);
                int y = get_id(q[i].y);
            if (q[i].e == 1)
            {
                join(x, y);
            }
            if(q[i].e ==0){
                if(find(x)==find(y)){
                // if(fa[x]==fa[y]){   错误 fa只是父节点，不一定是根节点
                    cout<<"NO"<<endl;
                    flag=0;
                    break;
                }
            }
        }
        if(flag)
        cout<<"YES"<<endl;
    }
}