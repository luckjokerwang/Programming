# import sys
# n,k,x =list(map(int,sys.stdin.readline().split()))
# a =list(map(int,sys.stdin.readline().split()))
# a.sort()
# for _ in range(k):
#     a[n-1]-=x
#     a.sort()
# print(a[n-1])

# 小根堆负数模拟大根堆,还是超时了
# import sys
# import heapq

# def solve():
#     n, k, x = map(int, sys.stdin.readline().split())
#     a = list(map(int, sys.stdin.readline().split()))
    
#     # 使用最大堆（通过存储负数实现）
#     max_heap = []
#     for num in a:
#         heapq.heappush(max_heap, -num)
    
#     for _  in range(k):
#         current_max = -heapq.heappop(max_heap)
#         new_val = current_max - x
#         heapq.heappush(max_heap,-new_val)
    
#     answer =-heapq.heappop(max_heap)
#     print(answer)


# if __name__ == "__main__":
#     solve()

# 二分法+贪心
# import operator
# import sys

# def solve():
#     n, k, x = map(int, sys.stdin.readline().split())
#     a = list(map(int, sys.stdin.readline().split()))

#     def is_possible(mid):
#         operations =0
#         for num in a:
#             if num>mid:
#                 ops =(num-mid+x-1)//x
#                 operations+=ops
#                 if operations>k:
#                     return False
#         return True
    
#     left=min(a)-k*x
#     right =max(a)
#     answer =right
#     while left<=right:
#         mid =(left+right)//2
#         if is_possible(mid):
#             answer =mid
#             right = mid-1
#         else:
#             left = mid+1
#     print(answer)

# if __name__ == "__main__":
#     solve()

#
