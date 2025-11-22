# import sys

# # 提高 Python 的递归深度限制，以防并查集的 find 操作在
# # 极端情况下（链状）递归过深。
# # 对于 n=100000, 设置为 n+50 比较安全。
# sys.setrecursionlimit(100050)

# # 定义并查集的数据结构
# parent = []

# def find(i):
#     """
#     找到节点 i 的根节点。
#     使用路径压缩 (Path Compression) 来优化。
#     """
#     if parent[i] == i:
#         return i
#     # 递归地找到根，并把路径上所有节点的 parent 直接设为根
#     parent[i] = find(parent[i])
#     return parent[i]

# def union(i, j):
#     """
#     合并节点 i 和节点 j 所在的集合。
#     返回 True 如果合并成功 (i 和 j 原本不相通)。
#     返回 False 如果合并失败 (i 和 j 原本已相通)。
#     """
#     root_i = find(i)
#     root_j = find(j)
    
#     if root_i != root_j:
#         # 将一个根的 parent 指向另一个根
#         parent[root_i] = root_j
#         return True
#     return False

# def solve():
#     try:
#         n_str = sys.stdin.readline()
#         if not n_str:
#             return  # 处理文件末尾
#         n = int(n_str.strip())
        
#         # 初始化并查集
#         # 使用 1-based 索引，所以数组大小为 n+1
#         global parent
#         parent = list(range(n + 1))
        
#         # 初始时，有 n 个连通分量
#         component_count = n
        
#         # 读取 n 条边
#         for _ in range(n):
#             line = sys.stdin.readline().split()
#             a = int(line[0])
#             b = int(line[1])
            
#             # 尝试合并
#             if union(a, b):
#                 # 如果合并成功，连通分量总数减 1
#                 component_count -= 1
        
#         # 检查最终的连通分量总数
#         if component_count == 1:
#             print("YES")
#         else:
#             print("NO")

#     except EOFError:
#         pass
#     except Exception as e:
#         # print(f"An error occurred: {e}", file=sys.stderr)
#         pass

# # 运行主函数
# solve()


#     import sys
# def find(a):
#     if parent[a]== a:
#         return a
#     parent[a]=find(parent[a])
#     return parent[a]
# def union(a,b):
#     root_a =find(a)
#     root_b =find(b)
#     if root_a !=root_b:
#         parent[root_a]=root_b
#         return True
#     return False
    

# n=int(sys.stdin.readline())
# parent =list(range(n+1))
# parent=[i for i in range(n+1)]
# component_count =n
# for _ in range(n):
#     a,b =list(map(int,sys.stdin.readline().split()))
#     if union(a,b):
#         component_count-=1
# if component_count ==1:
#     print("YES")
# else:
#     print("NO")

def find(i):
    if parent[i] == i:
        return i
    parent[i] = find(parent[i])
    return parent[i]


def union(i,j):
    root_i = find(i)
    root_j = find(j)
    if root_i != root_j:
        parent[root_i] = root_j
        return True
    return False

import sys
n=int(sys.stdin.readline())
parent=list(range(n+1))
component_count = n

for _ in range(n):
    a,b = map(int,sys.stdin.readline().split())
    if (union(a,b)):
        component_count -= 1
if component_count == 1:
     print("YES")
else:
    print("NO")

