import sys

def input():
    """Reads a line from standard input and strips trailing whitespace."""
    return sys.stdin.readline().strip()

def count_factor(n, factor):
    """计算数字 n 包含多少个因子 factor。"""
    count = 0
    if n == 0:
        return 0  # 根据题目约束，a_i >= 1，但为保险起见
    while n > 0 and n % factor == 0:
        count += 1
        n //= factor
    return count

def solve():
    try:
        n_str = input()
        if not n_str:
            return  # 处理空输入
        n = int(n_str)
        
        if n == 0:
            print(0)
            return
            
        a = list(map(int, input().split()))
        
        factors = []
        max_total_fives = 0
        for val in a:
            cnt2 = count_factor(val, 2)
            cnt5 = count_factor(val, 5)
            factors.append((cnt2, cnt5))
            max_total_fives += cnt5

        # 如果总共的5因子就是0，那么0的个数也一定是0
        if max_total_fives == 0:
            print(0)
            return

        INF = float('inf')
        
        # dp0[j] -> 考虑到 i-1, 不选 i-1 时，凑齐 j 个5所需的最少2
        # dp1[j] -> 考虑到 i-1, 选了 i-1 时，凑齐 j 个5所需的最少2
        dp0 = [INF] * (max_total_fives + 1)
        dp1 = [INF] * (max_total_fives + 1)
        
        # 基础状态：不考虑任何数(i=0)，0个5，0个2
        dp0[0] = 0
        
        # 遍历 n 个数
        for i in range(n):
            cnt2, cnt5 = factors[i]
            
            # new_dp0[j] -> 考虑到 i, 不选 i 时 ...
            # new_dp1[j] -> 考虑到 i, 选了 i 时 ...
            new_dp0 = [INF] * (max_total_fives + 1)
            new_dp1 = [INF] * (max_total_fives + 1)
            
            for j in range(max_total_fives + 1):
                
                # 1. 计算 new_dp0[j] (不选第 i 个数)
                #    状态可以从 "不选 i-1" (dp0[j]) 或 "选 i-1" (dp1[j]) 转移
                new_dp0[j] = min(dp0[j], dp1[j])
                
                # 2. 计算 new_dp1[j] (选第 i 个数)
                #    状态必须从 "不选 i-1" (dp0) 转移
                if j >= cnt5:
                    if dp0[j - cnt5] != INF:
                        new_dp1[j] = dp0[j - cnt5] + cnt2
            
            # 更新状态，为下一次循环 (i+1) 做准备
            dp0 = new_dp0
            dp1 = new_dp1
            
        max_zeros = 0
        # 遍历所有可能的5的个数
        for j in range(max_total_fives + 1):
            
            # 检查最后状态：不选最后一个数 (dp0[j])
            min_twos_not_taken = dp0[j]
            if min_twos_not_taken != INF:
                max_zeros = max(max_zeros, min(j, min_twos_not_taken))
                
            # 检查最后状态：选了最后一个数 (dp1[j])
            min_twos_taken = dp1[j]
            if min_twos_taken != INF:
                max_zeros = max(max_zeros, min(j, min_twos_taken))
                
        print(max_zeros)

    except EOFError:
        pass
    except Exception as e:
        # print(f"An error occurred: {e}", file=sys.stderr)
        pass

# 执行求解
solve()