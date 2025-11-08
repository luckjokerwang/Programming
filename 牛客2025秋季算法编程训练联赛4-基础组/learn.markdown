https://ac.nowcoder.com/acm/contest/120453
## A斐波那契
思路:预处理
要记得特殊判断
## B括号序列
思路:用栈写

## C子段异或
思路:前缀异或
基本概念
前缀异或：pref[i] 表示从数组开始到第i个元素的异或和
例如，pref[3] = a[0] ^ a[1] ^ a[2]
关键性质：子段 a[l..r] 的异或和 = pref[r] ^ pref[l-1]
这是因为 a[l] ^ ... ^ a[r] = (a[0]^...^a[r]) ^ (a[0]^...^a[l-1])
```python
from collections import defaultdict
freq = defaultdict(int)  # 哈希表，key: 前缀异或值, value: 出现次数
freq[0] = 1  # 初始化：空前缀出现1次

prefix = 0  # 当前前缀异或，初始为0
cnt = 0     # 计数器，合法子段数量

for i in range(n):
    prefix ^= a[i]  # 更新 prefix = prefix ^ a[i]，现在 prefix == a[0] ^ ... ^ a[i]，即 prefix[i+1]
    
    cnt += freq[prefix]  # 在更新频率前，添加之前相同 prefix 的次数。
                         # 每个这样的次数对应一个以 i 结尾、异或为0的子段。
                         # 为什么正确？因为 freq[prefix] 是截止到 i-1 的所有 prefix[j] (j <= i) 中等于当前 prefix 的数量，
                         # 但由于我们是先加 cnt 再更新 freq，所以是之前（j <= i）的数量，且 j=0 也包括（空前缀）。

    freq[prefix] += 1  # 更新当前 prefix 的频率，为后续 i 使用。
```
## 模逆元
模逆元：
```python
pow(a, mod-2, mod)相当与a^-1
```

## 贪心分配数字以最小化多数字和 
