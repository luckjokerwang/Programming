import math
n,x =map(int,input().split())
# print(n,x)
a=list(map(int,input().split()))
b=[1,]*n
for i in range(1,n):
    b[i]=b[i-1]*a[i]
# print(b)
cnt=0
for i in range(0,n):
    
    for j in range(i,n):
        temp =x
        if(j-i-1>=0):
            temp*=(b[j]/b[j-i-1])
        else:
            temp*=b[j]
        root =math.sqrt(temp)
        if(root ==int(root)):
            cnt+=1
print(cnt)
import sys
import random
from collections import defaultdict

def sieve_spf(n):
    spf = [0] * (n + 1)
    primes = []
    for i in range(2, n + 1):
        if spf[i] == 0:
            spf[i] = i
            primes.append(i)
        j = 0
        while j < len(primes) and primes[j] <= spf[i] and i * primes[j] <= n:
            spf[i * primes[j]] = primes[j]
            j += 1
    return spf, primes

def core_via_spf(x, spf):
    if x <= 1:
        return []
    ans = []
    while x > 1:
        p = spf[x]
        c = 0
        while x % p == 0:
            x //= p
            c ^= 1
        if c:
            ans.append(p)
    return ans

def core_general(x, primes):
    if x <= 1:
        return []
    ans = []
    for p in primes:
        if p * p > x:
            break
        if x % p == 0:
            c = 0
            while x % p == 0:
                x //= p
                c ^= 1
            if c:
                ans.append(p)
    if x > 1:
        ans.append(x)
    return ans

def solve():
    data = sys.stdin.read().strip().split()
    n = int(data[0]); x = int(data[1])
    a = list(map(int, data[2:2+n]))

    MAXA = 10**5
    spf, primes = sieve_spf(MAXA)

    random.seed(0)
    hval = {}
    def h(p):
        v = hval.get(p)
        if v is None:
            v = random.getrandbits(64)
            hval[p] = v
        return v

    target_primes = core_general(x, primes)
    target_hash = 0
    for p in target_primes:
        target_hash ^= h(p)

    pref = 0
    cnt = defaultdict(int)
    cnt[0] = 1
    ans = 0

    for num in a:
        if num <= MAXA:
            ps = core_via_spf(num, spf)
        else:
            ps = core_general(num, primes)
        cur = 0
        for p in ps:
            cur ^= h(p)
        pref ^= cur
        ans += cnt[pref ^ target_hash]
        cnt[pref] += 1

    print(ans)

if __name__ == "__main__":
    solve()