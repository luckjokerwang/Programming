# from collections import defaultdict


# n =int(input())
# a=list(map(int,input().split()))
# mod =1777777777
# d =[]
# prefix =0
# ans=1
# for i in range(n):
#     prefix^=a[i]
#     ans*=prefix%mod
#     d.append(prefix)
# for i in range(n):
#     for j in range(i+1,n):
#         temp =d[j]^d[i]
#         ans*=(ans*temp)%mod
# print(ans%mod)

from collections import defaultdict
 
 
n =int(input())
a=list(map(int,input().split()))
mod =1777777777
set ={0}
prefix =0
ans=1
if n>=8192:
    print(0)
else:
    for num in a:
        prefix^=num
        for p in set:
            ans=(ans*(prefix^p))%mod
            if(ans==0):
                break
        set.add(prefix)
        if(ans==0):
            break
    print(ans)