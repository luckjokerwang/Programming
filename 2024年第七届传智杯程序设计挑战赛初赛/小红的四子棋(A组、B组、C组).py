# import sys

# def solve():
#     data = sys.stdin.read().strip().split()
#     n, m = map(int, data[:2])
#     grid = data[2:2+n]

#     directions = [(0, 1), (1, 0), (1, 1), (1, -1)]

#     def in_bounds(x, y):
#         return 0 <= x < n and 0 <= y < m

#     def has_win(ch):
#         for i in range(n):
#             for j in range(m):
#                 if grid[i][j] != ch:
#                     continue
#                 for dx, dy in directions:
#                     # 剪枝：检查剩余空间是否可能达到4
#                     end_x = i + (4 - 1) * dx
#                     end_y = j + (4 - 1) * dy
#                     if not in_bounds(end_x, end_y):
#                         continue
#                     cnt = 0
#                     x, y = i, j
#                     while in_bounds(x, y) and grid[x][y] == ch:
#                         cnt += 1
#                         if cnt >= 4:
#                             return True
#                         x += dx
#                         y += dy
#         return False

#     if has_win('r'):
#         print("kou")
#     elif has_win('p'):
#         print("yukari")
#     else:
#         print("to be continued")

# if __name__ == "__main__":
#     solve()
##思路
##1.读取输入
##2.定义has_win函数 (O2循环 判断 是否连接和边界)
##3.定义in_bounds函数 (判断是否在边界)
##4.定义main函数 (读取输入 调用has_win函数)
##5.调用main函数
import sys


def main():
    data =sys.stdin.read().split()
    n,m =map(int,data[0:2])
    grid=data[2:2+n]
    directions=[(0,1),(1,0),(1,1),(1,-1)]
    def in_bounds(x,y):
        return 0<=x<n and 0<=y<m
    def has_win(ch):
        for i in range(n):
            for j in range(m):
                if grid[i][j]!=ch:
                    continue
                for dx,dy in directions:
                    end_x =i +3*dx
                    end_y =j +3*dy
                    if not in_bounds(end_x,end_y):
                        continue
                    win =True
                    for k in range(1,4):
                        if grid[i+k*dx][j+k*dy]!=ch:
                            win =False
                            break
                    if win:
                        return True
        return False
    if has_win('r'):
        print("kou")
    elif has_win('p'):
        print("yukari")
    else:
        print("to be continued")
                           

if __name__ == '__main__':
    main()

