## 严重超时
# from collections import defaultdict
# s = input()
# dict =defaultdict(int)
# t = ''
# for i in s:
#     dict[i]+=1
# for i in range(1,10):
#     t+=str(i)*dict[str(i)]
# if not dict['+']:
   
#     print(t)
# else:
#     n= dict['+']
#     a =['']*(n+1)
#     for i in range(len(t)):
#         a[i%(n+1)]+=t[i]
#     ans = sum(int(i) for i in a)
#     print(ans)            
## 真聪明 贪心分配数字以最小化多数字和
from collections import defaultdict
import sys

# 读取输入
s = sys.stdin.read().strip()

# 统计频率
freq = defaultdict(int)
for char in s:
    freq[char] += 1

# 准备 digits_list (sorted asc)
digits_list = []
for d in range(1, 10):
    digits_list.extend([d] * freq[str(d)])

m = len(digits_list)  # 总数字个数
n_plus = freq['+']
k = n_plus + 1

# 计算长度
base = m // k
rem = m % k
min_len = base
max_len = base + 1 if rem > 0 else base

# contrib[p] = sum of digits at 10^p
contrib = [0] * max_len

# 分配 digits 从小到大 到 p 从高到低
digit_idx = 0
for p in range(max_len - 1, -1, -1):
    threshold = p + 1
    if threshold > max_len:
        count_p = 0
    elif threshold <= min_len:
        count_p = k
    else:
        count_p = rem
    for _ in range(count_p):
        contrib[p] += digits_list[digit_idx]
        digit_idx += 1

# 构建 sum 字符串，处理 carry
sum_digits = []
carry = 0
for p in range(max_len):
    total = contrib[p] + carry
    sum_digits.append(str(total % 10))
    carry = total // 10

while carry:
    sum_digits.append(str(carry % 10))
    carry //= 10

# 逆转并去前导零
res = ''.join(reversed(sum_digits)).lstrip('0')
if not res:
    res = '0'

print(res)