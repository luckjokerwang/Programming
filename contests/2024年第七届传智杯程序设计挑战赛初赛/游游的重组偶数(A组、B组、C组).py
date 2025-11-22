import sys

def solve(num:int)->int:
    s=str(num)
    n=len(s)
    last_even_pos =-1
    for i in range(n-1,-1,-1):
        if(int(s[i])%2==0):
            last_even_pos =i
            break
    if(last_even_pos==-1):
        return -1
    result = []
    for i in range(n):
        if i!=last_even_pos:
            result.append(s[i])
    result.append(s[last_even_pos])
    
    if result[0]=='0':
        for i in range(1,n):
            if result[i]!='0':
                result[0],result[i]=result[i],result[0]
                break
        if result[0]=='0':
            return -1
    return ''.join(result)
    
data =list(map(int,sys.stdin.read().strip().split()))
q =data[0]
a =data[1:]
for num in a:
    print(solve(num))

## 考虑0的特判