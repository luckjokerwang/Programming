# n =int(input())
# cntx1,cntx2,cntx3,cnty1,cnty2,cnty3=0,0,0,0,0,0
# for _ in range(n):
#     x,y =map(int,input().split())
#     if x>0:
#         cntx1+=1
#     elif x<0:
#         cntx2+=1
#     else:
#         cntx3+=1
#     if y>0:
#         cnty1+=1
#     elif y<0:
#         cnty2+=1
#     else:
#         cnty3+=1
# count1=min(cntx1,cntx2)+cntx3
# count2=min(cnty1,cnty2)+cnty3
# print(count1+count2)

import sys

it = iter(sys.stdin.buffer.read().split())
n = int(next(it))

cxp = cxn = cyp = cyn = 0
for _ in range(n):
    x = int(next(it)); y = int(next(it))
    if x > 0: cxp += 1
    else:     cxn += 1
    if y > 0: cyp += 1
    else:     cyn += 1

print(min(cxp, cxn) + min(cyp, cyn))