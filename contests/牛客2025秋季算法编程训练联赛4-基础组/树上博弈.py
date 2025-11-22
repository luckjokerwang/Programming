import sys
from collections import deque

input = sys.stdin.read
data = input().split()

n = int(data[0])
p = [0] * (n + 1)
for i in range(2, n + 1):
    p[i] = int(data[i - 1])

# Build adjacency list
adj = [[] for _ in range(n + 1)]
for i in range(2, n + 1):
    adj[p[i]].append(i)
    adj[i].append(p[i])

# BFS to assign levels
level = [-1] * (n + 1)
level[1] = 0
q = deque([1])
cnt_even = 1  # root level 0 even
cnt_odd = 0

while q:
    u = q.popleft()
    for v in adj[u]:
        if level[v] == -1:
            level[v] = level[u] + 1
            if level[v] % 2 == 0:
                cnt_even += 1
            else:
                cnt_odd += 1
            q.append(v)

ans = cnt_even * (cnt_even - 1) + cnt_odd * (cnt_odd - 1)
print(ans)