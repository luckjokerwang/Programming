# import sys
# from collections import defaultdict,Counter
# t =int(input())
# while t:
#     n,q=list(map(int,sys.stdin.readline().split()))
#     a =list(map(int,sys.stdin.readline().split()))
#     d=list(map(int,sys.stdin.readline().split()))
#     t-=1
#     max_day =max(d)
#     sort_d =sorted(set(d))
#     l =len(a)
#     day_to_ans = {}
#     dict =defaultdict(int)
#     for num in a:
#         dict[num]+=1
#     count =Counter(dict.values())
#     prev_day =0
#     for day in sort_d:
#         for day_num in range(prev_day + 1, day + 1):
#             if day_num in count:
#                 l -= count[day_num]*day_num
#         day_to_ans[day] = l
#         prev_day = day
#     for day in d:
#         print(day_to_ans.get(day, 0), end=" ")
    
    
# import sys
# from collections import Counter

# def solve():
#     input = sys.stdin.read
#     data = input().split()
#     idx = 0
    
#     t = int(data[idx])
#     idx += 1
#     results = []
    
#     for _ in range(t):
#         n, q = map(int, data[idx:idx+2])
#         idx += 2
        
#         a = list(map(int, data[idx:idx+n]))
#         idx += n
        
#         d = list(map(int, data[idx:idx+q]))
#         idx += q
        
#         # 统计每个数出现的次数
#         freq = Counter(a)
#         # 统计每个出现次数的频率
#         count = Counter(freq.values())
        
#         # 获取所有需要处理的天数并去重排序
#         days = sorted(set(d))
#         day_to_ans = {}
#         current = len(freq)  # 初始不同水果数量
        
#         # 预处理每个天数的答案
#         prev_day = 0
#         for day in days:
#             # 处理之前的天数
#             for day_num in range(prev_day + 1, day + 1):
#                 if day_num in count:
#                     current -= count[day_num]
#             day_to_ans[day] = current
#             prev_day = day
        
#         # 收集结果
#         results.append(' '.join(str(day_to_ans.get(day, 0)) for day in d))
    
#     # 一次性输出所有结果
#     print('\n'.join(results))

# if __name__ == "__main__":
#     solve()
    

import sys
from collections import Counter

# 将每个测试用例的逻辑封装成一个函数
def solve():
    try:
        # 使用 sys.stdin.readline() 读取所有行，速度更快
        n_q_line = sys.stdin.readline().split()
        if not n_q_line:
            return False  # 输入结束
        n, q = map(int, n_q_line)

        a_line = sys.stdin.readline().split()
        if not a_line:
            return False
        a = list(map(int, a_line))

        d_line = sys.stdin.readline().split()
        if not d_line:
            return False
        d = list(map(int, d_line))

    except (IOError, ValueError, EOFError):
        return False # 处理可能的输入异常

    # 1. 统计每种水果的数量 (e.g., {1: 1, 2: 2, 3: 3, 4: 2})
    type_counts = Counter(a)
    
    # 2. 统计 "数量" 的 "数量"
    # (e.g., {1: 1, 2: 2, 3: 1} -> 1种水果有1个, 2种水果有2个, 1种水果有3个)
    freq_counts = Counter(type_counts.values())

    # 关键修正点 1：最大相关天数是 n，不是 max(d)
    max_relevant_day = n
    
    # 关键修正点 2：数组大小为 n + 1
    # ans[i] 将存储第 i 天 *之后* 剩余的果子数量
    ans = [0] * (max_relevant_day + 1)
    
    current_fruits = n
    ans[0] = current_fruits # 第 0 天后，还是 n 个

    # 关键修正点 3：循环只到 n
    for day in range(1, max_relevant_day + 1):
        # 在第 day 天，打掉所有数量 *恰好* 为 day 的
        fruits_removed_today = freq_counts[day] * day
        current_fruits -= fruits_removed_today
        ans[day] = current_fruits # 记录第 day 天*之后*的结果

    # --- 回答询问 ---
    results_to_print = []
    for query_day in d:
        # 关键修正点 4：处理大于 n 的询问
        if query_day > max_relevant_day:
            # 如果询问的天数 > n，结果和第 n 天一样
            results_to_print.append(ans[max_relevant_day])
        else:
            # 否则，直接用预处理的结果
            results_to_print.append(ans[query_day])
    
    # 使用 join 一次性输出，比多次 print(..., end=" ") 稍快
    print(*results_to_print)
    
    return True

# --- 主程序 ---
try:
    t_line = sys.stdin.readline()
    if not t_line:
        t = 0
    else:
        t = int(t_line.strip())
except (IOError, ValueError):
    t = 0 # 异常时退出

while t > 0:
    if not solve():
        break # 如果 solve 返回 False (输入结束)，则退出循环
    t -= 1