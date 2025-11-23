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

