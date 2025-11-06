import bisect
from math import ldexp
import sys

data=list(map(int,sys.stdin.buffer.read().split()))

n=data[0]
a=data[1:]
if n<=1:
    print(n)
    raise SystemExit

lis=[0]*n
tails =[]

for i,x in enumerate(a):
    pos = bisect.bisect_right(tails,x)
    if pos == len(tails):
        tails.append(x)
    else:
        tails[pos]=x
    lis[i]=pos+1

lds = [0]*n
tails =[]
for i in range(n-1,-1,-1):
    x =a[i]
    pos =bisect.bisect_right(tails,x)
    if pos ==len(tails):
        tails.append(x)
    else:
        tails[pos] =x    
    lds[i] =pos+1
ans =0
for i in range(n):
    ans =max(ans,lis[i]+lds[i]-1)
print(ans)