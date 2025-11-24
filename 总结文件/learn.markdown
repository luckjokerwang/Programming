## 如果一个cout没有输出,大概率是死循环了
## 要常思考
char+int = int;所有要用char(char +int)

## 一次校赛可以看出我思维逻辑混乱,基础不扎实
悟以往之不谏,知来者之可追
多思考,多总结
理清逻辑再写代码
## 注意看题目!!!

## accumulate 函数用法

**头文件**：`#include <numeric>`

**功能**：计算容器中元素的累加和（或自定义操作的累积结果）

**基本语法**：
```cpp
accumulate(起始迭代器, 结束迭代器, 初始值);
accumulate(起始迭代器, 结束迭代器, 初始值, 自定义操作);
```

**常见用法**：

1. **求和（整数）**：
```cpp
vector<int> v = {1, 2, 3, 4, 5};
int sum = accumulate(v.begin(), v.end(), 0);  // sum = 15
```

2. **求和（避免溢出，用 long long）**：
```cpp
vector<int> c = {100, 200, 300};
ll total = accumulate(c.begin(), c.end(), 0LL);  // 0LL 是 long long 类型的初始值
```

3. **求乘积**：
```cpp
vector<int> v = {2, 3, 4};
int product = accumulate(v.begin(), v.end(), 1, multiplies<int>());  // product = 24
```

4. **自定义操作（lambda）**：
```cpp
vector<int> v = {1, 2, 3, 4};
int result = accumulate(v.begin(), v.end(), 0, [](int a, int b) {
    return a + b * b;  // 计算平方和
});  // result = 1 + 4 + 9 + 16 = 30
```

**注意事项**：
- 初始值类型决定返回值类型，避免溢出时用 `0LL`（long long）或 `0.0`（double）
- 默认操作是加法 `+`，可通过第四个参数自定义操作
- 时间复杂度 O(n)

**典型应用场景**：
- 二分答案中计算上界：`right = (accumulate(c.begin(), c.end(), 0LL) + m) / n;`
- 统计总和、平均值
- 字符串拼接：`accumulate(words.begin(), words.end(), string(""));`

## +的优先级大于>>，注意加括号

## 过了样例但是代码没通过一定要先回头重新看题目,看是不是理解错了,只考虑到了一种情况,在看代码能否优化
要把每个要求都理解到位,不要漏掉任何一个要求,不要闲蛮烦,过不了就苦了，要注意看 是不是没加 long long

## C++ string 常用函数

**头文件**：`#include <string>`

### 1. 基本操作
```
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);  // 读取整行，包括空格
    cout << s << endl;
    return 0;
}
```
**长度获取**：
```cpp
string s = "hello";
s.size();      // 5
s.length();    // 5（与 size() 等价）
s.empty();     // false（判断是否为空）
```

**访问元素**：
```cpp
s[0];          // 'h'（下标访问，不检查越界）
s.at(0);       // 'h'（下标访问，越界会抛出异常）
s.front();     // 'h'（第一个字符）
s.back();      // 'o'（最后一个字符）
```

### 2. 修改操作

**添加（尾部）**：
```cpp
s.push_back('!');        // s = "hello!"
s += " world";           // s = "hello! world"
s.append(" test");       // s = "hello! world test"
```

**删除操作**：
```cpp
// 删除最后一个字符
s.pop_back();            // 删除末尾字符

// 删除指定位置的字符
s.erase(0, 2);           // 从位置 0 开始删除 2 个字符
s.erase(s.begin());      // 删除第一个字符（迭代器）
s.erase(s.begin(), s.begin() + 3);  // 删除前 3 个字符

// 清空字符串
s.clear();               // s = ""
```

**插入操作**：
```cpp
s.insert(0, "Hi ");      // 在位置 0 插入 "Hi "
s.insert(s.begin(), 'A'); // 在开头插入字符 'A'
```

**替换操作**：
```cpp
s.replace(0, 2, "XX");   // 从位置 0 开始替换 2 个字符为 "XX"
```

### 3. 查找操作

**查找子串**：
```cpp
string s = "hello world";
s.find("world");         // 返回 6（首次出现位置）
s.find("abc");           // 返回 string::npos（未找到）
s.rfind("o");            // 返回 7（最后一次出现位置）
s.find('o')!=string::npos; // 判断是否存在子串
// 从指定位置开始查找
s.find("o", 5);          // 从位置 5 开始查找 "o"
```

**查找字符**：
```cpp
s.find_first_of("aeiou");     // 查找第一个元音字母
s.find_last_of("aeiou");      // 查找最后一个元音字母
s.find_first_not_of(" ");     // 查找第一个非空格字符
```

### 4. 截取与比较

**截取子串**：
```cpp
string s = "hello world";
s.substr(0, 5);          // "hello"（从位置 0 开始，长度 5）
s.substr(6);             // "world"（从位置 6 到末尾）
```

**比较**：
```cpp
s.compare("hello");      // 返回 0（相等），< 0（小于），> 0（大于）
s == "hello";            // true（可直接用运算符比较）
```

### 5. 转换操作

**数字与字符串互转**：
```cpp
// 字符串转数字
int num = stoi("123");        // 123
long long ll = stoll("123456789");
double d = stod("3.14");

// 数字转字符串
string s = to_string(123);    // "123"
```

**大小写转换**（需配合 algorithm）：
```cpp
#include <algorithm>
#include <cctype>

string s = "Hello";
transform(s.begin(), s.end(), s.begin(), ::tolower);  // s = "hello"
transform(s.begin(), s.end(), s.begin(), ::toupper);  // s = "HELLO"
```

### 6. 其他常用操作

**反转字符串**：
```cpp
#include <algorithm>
reverse(s.begin(), s.end());
```

**排序字符串**：
```cpp
sort(s.begin(), s.end());    // 按字典序排序
```

**字符串拼接**：
```cpp
vector<string> words = {"hello", "world"};
string result = accumulate(words.begin(), words.end(), string(""));
// result = "helloworld"
```

### 7. 常见题型应用

**删除空格**：
```cpp
s.erase(remove(s.begin(), s.end(), ' '), s.end());
```

**分割字符串**：
```cpp
stringstream ss(s);
string word;
while (ss >> word) {
    // 处理每个单词
}
```

**判断回文**：
```cpp
string rev = s;
reverse(rev.begin(), rev.end());
bool isPalindrome = (s == rev);
```

### 注意事项
- `erase()` 返回删除位置后的迭代器，可以连续删除
- `find()` 返回 `string::npos` 表示未找到（值为 -1 或最大无符号整数）
- 字符串下标从 0 开始
- `substr(pos, len)` 中 len 是长度，不是结束位置

## 看到有mod就无脑用 :
```
define int long long
signed main() {
}

## setprecision 用法
原理: 设置输出浮点数的精度

```cpp
#include <iostream>
using namespace std;
        cout << fixed << setprecision(8);
        == 设置小数点后8位
        //举例子
        double x = 3.141592653589793;
        cout << fixed << setprecision(4) << x << "\n"; // 3.1416
        cout << fixed << setprecision(10) << x << "\n"; // 3.1415926536
```

## 数学问题 - 数字拼接取模
**问题类型**：D_183183.cpp

**核心思路**：
- 对于 f(a,b) = (a*10^d + b) % m，转换为 (a*10^d)%m + b%m ≡ 0 (mod m)
- 预处理每个数的位数 d 和模 m 的结果
- 用 map 统计 (d, mod) 组合的出现次数
- 对每个 a，枚举所有位数 d，计算需要的模值 needed_mod = (m - (a*10^d)%m) % m

**关键点**：
```cpp
// 计算 10^d % m 时要边乘边取模
int pow10 = 1;
for(int k = 0; k < d; k++){
    pow10 = (pow10 * 10) % m;
}
```

**易错点**：
- 忘记对 10 的幂次取模，导致溢出
- 公式推导：从 (a*10^d + b) % m = 0 推出需要的 b%m

---

## 字符串 - 回文扩展/连续字符
**问题类型**：C_1122_Substring_2.cpp

**核心思路**：
- 找到所有满足 s[i] == s[i-1] + 1 的位置（连续递增）
- 从这些位置向两边扩展，统计能形成多少对称的连续递增串

**关键代码**：
```cpp
// 以 index[i] 为中心向两边扩展
int num = 1;
while(n-num-1 >= 0 && n+num < s.size() &&
      s[n-num-1] == s[n-1] && s[n+num] == s[n]){
    num++;
}
ans += num;
```

**思维要点**：
- 类似回文串扩展，但条件是字符连续性
- 注意边界检查：n-num-1 >= 0 和 n+num < s.size()

---

## 单调栈 - 找最近更大元素
**问题类型**：B_Nearest_Taller.cpp

**暴力做法问题**：
```cpp
// 当前代码 O(n²)，会超时
for(int i = 1; i <= n; i++){
    for(int j = i; j >= 1; j--){
        if(a[i] < a[j]){
            cout << j << endl;
            break;
        }
    }
}
```

**正确做法 - 单调栈 O(n)**：
```cpp
stack<int> st;  // 存储下标
vector<int> ans(n+1, -1);
for(int i = 1; i <= n; i++){
    // 维护单调递减栈（栈顶最小）
    while(!st.empty() && a[st.top()] < a[i]){
        ans[st.top()] = i;
        st.pop();
    }
    st.push(i);
}
```

**教训**：
- 看到"找左边/右边第一个更大/更小"的问题 → 想到单调栈
- 暴力双重循环容易超时

---

## 数学枚举 - 线性方程求解
**问题类型**：A_Happy_Birthday_4.cpp

**思路**：
- 求是否存在 i 使得 x+i = (y+i)*z
- 化简：x + i = yz + iz → i(1-z) = yz - x → i = (yz-x)/(1-z)

**优化点**：
```cpp
// 直接计算，不需要枚举 10000 次
if(z == 1){
    cout << (x == y ? "Yes" : "No") << endl;
} else {
    int numerator = y*z - x;
    int denominator = 1 - z;
    if(numerator % denominator == 0 && numerator / denominator >= 0){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
```

**教训**：
- 能用数学公式直接算的不要暴力枚举
- 注意特殊情况（z=1 时分母为 0）

---

## 计算几何 - 圆内三角形
**问题类型**：简单的三角形构造_A组.cpp

**核心思路**：
1. 求点 P 到圆心的单位向量 (ux, uy)
2. 若 d < r/2，取 d；否则最优距离为 r/2
3. 最大面积：max_area = w * h，其中 w = √(r²-d²)，h = r+d
4. 若 max_area < S，输出 -1

**构造顶点**：
```cpp
double x1 = x - r*ux, y1 = y - r*uy;  // 顶点（圆边缘）
double mx = x + d*ux, my = y + d*uy;  // 弦中点
double x2 = mx - w*uy, y2 = my + w*ux;  // 底边点1（垂直方向）
double x3 = mx + w*uy, y3 = my - w*ux;  // 底边点2
```

**易错点**：
- 变量名复用（d 既表示距离又表示弦距）→ 应该用不同变量名
- 忘记向量垂直化：(ux,uy) → (-uy,ux)
- 浮点精度比较用 < s-1e-7 而不是 < s

---

## 树上匹配 - DFS + 染色
**问题类型**：红和蓝_A组_B组.cpp

**思路**：
1. DFS 找完美匹配（每个节点都有配对）
2. 从根节点开始染色，配对的两个点同色，相邻配对异色

**关键代码**：
```cpp
// 匹配 DFS
void dfs_match(int u, int p){
    for(int v : adj[u]){
        if(v == p) continue;
        dfs_match(v, u);
        if(!possible) return;  // 提前剪枝
        if(match[v] == 0){
            if(match[u] == 0){
                match[v] = u; match[u] = v;
            } else {
                possible = false; return;
            }
        }
    }
}

// 染色 DFS
void dfs_color(int u, char c){
    int partner = match[u];
    color[u] = color[partner] = c;
    char next_c = (c == 'R' ? 'B' : 'R');
    // 递归处理 u 和 partner 的其他邻居
}
```

**注意事项**：
- n 必须是偶数才可能有完美匹配
- 用 possible 标记提前终止，避免无效计算
- 染色时要同时处理配对节点的所有邻居

---

## 刷题心得总结

### 1. 模运算常见坑
- **公式转换**：(a*b + c) % m = ((a*b)%m + c%m) % m
- **幂次取模**：计算 10^d % m 时要边乘边取模
- **见到 mod 就用 long long**

### 2. 数据结构选择
- 找"最近更大/更小" → **单调栈**
- 统计 (key, value) 组合 → **map<int, map<int, int>>**
- 树的遍历/匹配 → **DFS + 标记数组**

### 3. 代码细节
- **变量命名清晰**：不要复用变量（如 d 既表示距离又表示其他）
- **边界检查**：数组访问前检查 i-1 >= 0 和 i+1 < n
- **提前剪枝**：用 flag 标记提前 return，避免无效计算
- **浮点比较**：用 s - 1e-7 而不是直接 < s

### 4. 思维习惯
- **先化简公式再编码**：数学问题先推导，能算就不枚举
- **找规律**：字符串/序列问题找递推关系
- **画图理解**：几何问题务必画图，标出向量和垂直关系