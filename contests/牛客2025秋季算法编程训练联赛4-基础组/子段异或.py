import sys
data = sys.stdin.buffer.read().split()
n =int(data[0])
a=list(map(int,data[1:]))
pref = 0
freq = {0:1}
ans = 0
for v in a:
    pref ^= v
    ans += freq.get(pref, 0)
    freq[pref] = freq.get(pref, 0) + 1
print(ans)