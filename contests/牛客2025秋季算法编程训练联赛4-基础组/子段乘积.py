# from itertools import accumulate
# from operator import mul
# from functools import reduce
# import sys
# data = sys.stdin.read().split()
# n,k = map(int,data[0:2])
# a = list(map(int,data[2:2+n]))
# temp=1
# mod =998244353
# b=[]
# c =list(list())
# m=0
# for i in range(n):
#     if a[i]!=0:
#         b.append(a[i])
#     else:
#         c.append(b)
#         b=[]
# c.append(b)
# # print(c)
# ans =0
# for list in c:
#     if len(list)<k:
#         continue
#     else:
#         temp =reduce(mul,list[0:k])
#         ans =max(ans,temp%mod)
#         for i in range(k,len(list)):
#             temp =temp//list[i-k]*list[i]
#             ans =max(ans,temp%mod)
            
# print(ans)   
## 更慢
# import sys
# data = sys.stdin.read().split()
# n,k = map(int,data[0:2])
# a = list(map(int,data[2:2+n]))
# mod =998244353
# b=[]
# c =list(list())
# ans =0
# for i in range(n):
#     if a[i]!=0:
#         b.append(a[i])
#     else:
#         c.append(b)
#         b=[]
# c.append(b)
# for seg in c:
#     if len(seg)<k:
#         continue
#     prod =1
#     for i in range(k):
#         prod*=seg[i]%mod
#     ans =max(ans,prod%mod)
#     for i in range(k,len(seg)):
#         out = seg[i-k]
#         inn = seg[i]
#         prod =(prod*pow(out,mod-2,mod))%mod
#         prod*=inn%mod
#         ans =max(ans,prod%mod)
# print(ans)

## 答案
from functools import reduce
from operator import mul
import sys

data = sys.stdin.read().split()
n, k = map(int, data[0:2])
a = list(map(int, data[2:2 + n]))
mod = 998244353
b = []
c = []
for i in range(n):
    if a[i] != 0:
        b.append(a[i])
    else:
        c.append(b)
        b = []
c.append(b)

ans = 0
for lst in c:
    m = len(lst)
    if m < k:
        continue
    # Compute initial product mod mod
    temp = 1
    for i in range(k):
        temp = (temp * lst[i]) % mod
    ans = max(ans, temp)
    # Sliding window
    for i in range(k, m):
        prev = lst[i - k]
        inv_prev = pow(prev, mod - 2, mod)
        temp = (temp * inv_prev % mod) * lst[i] % mod
        ans = max(ans, temp)

print(ans)