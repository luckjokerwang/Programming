// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// multiset<string> st;
// int n;
// string s;
// signed main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin>>n;
//     while(n--){
//         cin>>s;
//         st.insert(s);
//     }
//     vector<bool> vis(n);
//     function<void(int x)> dfs=[&](int x){

//     };
//     dfs(1);
//     return 0;
// }
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

const int MAXN = 1005;
string words[MAXN];
int n;
int in[26], out[26];     // 记录入度和出度
vector<int> adj[26];     // 邻接表，存的是单词在words数组中的下标
bool visited[MAXN];      // 标记单词（边）是否被使用过
stack<int> path;         // 存储结果路径（存下标）

// Hierholzer 算法寻找欧拉路径
void dfs(int u) {
    // 遍历从 u 出发的所有边
    // 注意：这里的 adj[u] 已经是按照字典序排好的（因为 words 排序过且按顺序插入）
    for (int i = 0; i < adj[u].size(); ++i) {
        int edge_idx = adj[u][i];
        if (!visited[edge_idx]) {
            visited[edge_idx] = true;
            // 递归访问该边的终点
            // 终点是单词的最后一个字符
            int v = words[edge_idx].back() - 'a';
            dfs(v);
            // 回溯时将单词加入路径栈
            path.push(edge_idx);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    // 1. 排序，保证字典序最小
    sort(words, words + n);

    // 2. 建图 & 统计度数
    for (int i = 0; i < n; ++i) {
        int u = words[i].front() - 'a'; // 首字母
        int v = words[i].back() - 'a';  // 尾字母
        adj[u].push_back(i);            // 记录边的编号
        out[u]++;
        in[v]++;
    }

    // 3. 寻找起点并检查度数合法性
    int start_node = -1;
    int cnt_start = 0, cnt_end = 0;
    bool impossible = false;

    // 先找必定是起点的点 (out = in + 1)
    for (int i = 0; i < 26; ++i) {
        if (out[i] == in[i] + 1) {
            cnt_start++;
            start_node = i;
        } else if (in[i] == out[i] + 1) {
            cnt_end++;
        } else if (in[i] != out[i]) {
            impossible = true; // 除了起点终点，其他点必须出入度相等
        }
    }

    // 判定情况
    if (impossible) {
        cout << "***" << endl;
        return 0;
    }

    if (cnt_start == 1 && cnt_end == 1) {
        // 情况 A: 欧拉路径，起点已确定
    } else if (cnt_start == 0 && cnt_end == 0) {
        // 情况 B: 欧拉回路，起点可以是任意有出度的点
        // 为了字典序最小，我们要从排序后的第一个单词的首字母开始
        start_node = words[0].front() - 'a';
    } else {
        // 其他情况（如起点多于1个等）
        cout << "***" << endl;
        return 0;
    }

    // 4. 执行 DFS
    dfs(start_node);

    // 5. 检查连通性
    // 如果路径长度不等于 N，说明图不连通（有边没走到）
    if (path.size() != n) {
        cout << "***" << endl;
        return 0;
    }

    // 6. 输出结果
    // 栈中存的是逆序的路径，pop出来就是正序
    bool first = true;
    while (!path.empty()) {
        if (!first) cout << ".";
        cout << words[path.top()];
        path.pop();
        first = false;
    }
    cout << endl;

    return 0;
}