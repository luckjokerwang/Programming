
                    
import sys
from collections import defaultdict

MOD = 10**9 + 7

def solve():
    sys.setrecursionlimit(1 << 25)
    n = int(sys.stdin.readline())
    color = sys.stdin.readline().strip()
    parent = list(map(int, sys.stdin.readline().split()))
    
    # 构建树
    tree = defaultdict(list)
    for i in range(2, n+1):
        p = parent[i-2]
        tree[p].append(i)
    
    # dp[u][r] 表示以u为根的子树，和模3等于r的方案数
    dp = [[0]*3 for _ in range(n+1)]
    
    # 后序遍历
    stack = [(1, False)]
    while stack:
        u, visited = stack.pop()
        if not visited:
            stack.append((u, True))
            # 将子节点按顺序压入栈
            for v in reversed(tree[u]):
                stack.append((v, False))
        else:
            # 处理当前节点
            is_red = (color[u-1] == 'R')
            # 初始化dp[u]
            # 如果是叶子节点
            if not tree[u]:
                # 可以选择1或2
                dp[u][1 % 3] = 1
                dp[u][2 % 3] = 1
                if is_red:
                    # 红色叶子节点必须满足和是3的倍数，但1和2都不是3的倍数
                    dp[u] = [0] * 3
            else:
                # 非叶子节点，初始化为[1,0,0]
                dp[u] = [1, 0, 0]
                for v in tree[u]:
                    # 合并子节点的dp
                    temp = [0] * 3
                    for r1 in range(3):
                        if dp[u][r1] == 0:
                            continue
                        for r2 in range(3):
                            if dp[v][r2] > 0:
                                new_r = (r1 + r2) % 3
                                temp[new_r] = (temp[new_r] + dp[u][r1] * dp[v][r2]) % MOD
                    dp[u] = temp
                
                # 当前节点可以选择1或2
                new_dp = [0]*3
                for r in range(3):
                    if dp[u][r] > 0:
                        # 选择1
                        new_r = (r + 1) % 3
                        new_dp[new_r] = (new_dp[new_r] + dp[u][r]) % MOD
                        # 选择2
                        new_r = (r + 2) % 3
                        new_dp[new_r] = (new_dp[new_r] + dp[u][r]) % MOD
                dp[u] = new_dp
                
                if is_red:
                    # 如果是红色节点，只保留sum ≡ 0 mod 3的情况
                    total = dp[u][0]
                    dp[u] = [0]*3
                    dp[u][0] = total
    
    # 根节点的和可以是任意值，因为题目只要求红色节点的子树和模3为0
    total = 0
    for r in range(3):
        total = (total + dp[1][r]) % MOD
    print(total)

solve()