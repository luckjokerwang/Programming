# import sys
# data = list(map(int,sys.stdin.read().split()))

# n=data[0]
# k=data[1]
# a=data[2:]
# b=sorted(a)
# sum =0
# cnt =0
# for num in b:
#     sum+=num
#     if(sum<=k):
#         cnt+=1
#     else:
#         break
        
# print(cnt)
import sys
from itertools import accumulate
from bisect import bisect_right

data = list(map(int, sys.stdin.read().split()))
n, k = data[0], data[1]
a = data[2:]

a.sort()
prefix = list(accumulate(a))
# 找到最后一个 <= k 的前缀位置，结果即为可以选的个数
ans = bisect_right(prefix, k)
print(ans)