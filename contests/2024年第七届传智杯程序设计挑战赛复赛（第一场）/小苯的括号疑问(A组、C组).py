import sys
n =int(input())
for _ in range(n):
    s=input()
    l =len(s)
    if l%2==1:
        print(-1) 
    elif l==2:
        print("()")
    else:
        print("There are multiple solutions")