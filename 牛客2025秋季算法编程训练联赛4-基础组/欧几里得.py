import sys

# 读取所有整数，兼容空格/换行分隔
data = list(map(int, sys.stdin.read().strip().split()))
if not data:
    sys.exit(0)

T = data[0]
ns = data[1:1 + T]

max_n = max(ns) if ns else 0
# 预计算斐波那契：fib[0]=0, fib[1]=1
fib = [0, 1]
for i in range(2, max_n + 4):  # 需要到索引 n+3
    fib.append(fib[i - 1] + fib[i - 2])

out = []
for n in ns:
    if n == 0:
        out.append("1")
    else:
        out.append(str(fib[n + 3]))

print("\n".join(out))