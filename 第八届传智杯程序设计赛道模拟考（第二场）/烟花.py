n=int(input())
l =[]
for i in range(n-1,-1,-1):
    s=f"\\{' '*i}|{' '*i}/"
    s1 =' '*(n-1-i)+s
    s2 =' '*(n-1-i)+'/'+s[1:-1]+'\\'
    l.append(s2)
    print(s1)
print(f"{'-'*n}O{'-'*n}")
for i in reversed(l):
    print(i)
