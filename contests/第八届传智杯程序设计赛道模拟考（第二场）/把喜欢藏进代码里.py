# import sys
# lan =sys.stdin.readline().split(".")
# n =int(input())
# index =1
# while index<=n:
#     if(lan[1][0]=='c' or lan[1][0]=='j'  or lan[1]=='go'):
#         com =["//","/*"]
#         data =sys.stdin.readline().split(com[0])
#         if len(data)>1:
#             print(f"#{index}:{data[1]}")
#     elif lan[1][0]=='p':
#         com ="#"
#         data =sys.stdin.readline().split(com)
#         if len(data)>1:
#             print(f"#{index}:{data[1]}")
#     index+=1

import sys

def print_comment(line_num, content):
    """
    按题目要求格式化输出，并处理转义字符。
    std::quoted(s) 在 C++ 中的效果等同于：
    1. 将 s 中的 \ 替换为 \\
    2. 将 s 中的 " 替换为 \"
    3. 在最外面加上 "..."
    """
    # 替换 \ 和 "
    escaped_content = content.replace('\\', '\\\\').replace('"', '\\"')
    # 使用 sys.stdout.write 以避免 print 的额外开销，并格式化输出
    sys.stdout.write(f"#{line_num}: \"{escaped_content}\"\n")

def solve():
    # 使用 sys.stdin.readline() 读取，速度更快
    filename = sys.stdin.readline().strip()
    
    # 如果读到空行 (EOF)，则退出
    if not filename:
        return
    
    try:
        n_line = sys.stdin.readline().strip()
        n = int(n_line)
    except (ValueError, EOFError):
        # 处理可能的读取错误或文件结尾
        return
        
    ext = filename.split('.')[-1]
    
    # 根据文件后缀名，定义注释规则
    line_markers = []
    block_markers = [] # 存储 (start_marker, end_marker)
    
    if ext in {'c', 'cpp', 'cxx', 'cc', 'go', 'java', 'js'}:
        line_markers = ['//']
        block_markers = [('/*', '*/')]
    elif ext == 'php':
        line_markers = ['//', '#']
        block_markers = [('/*', '*/')]
    elif ext == 'py':
        line_markers = ['#']
        # 题目保证块注释不跨行
        block_markers = [('"""', '"""'), ("'''", "'''")]
    elif ext == 'html':
        line_markers = []
        block_markers = [('')]
    
    # 逐行处理代码
    for line_num in range(1, n + 1):
        line = sys.stdin.readline().rstrip('\n')
        
        idx = 0 # 当前在行内的搜索起始位置
        
        # 循环，以便处理一行上的多个注释 (如: /* c1 */ code /* c2 */)
        while idx < len(line):
            
            # 查找*最早*出现的注释标记
            best_start = float('inf') # 最早的开始位置
            found_marker_type = None  # 'line' or 'block'
            found_marker = None       # 找到的标记本身
            
            # 1. 查找最早的行注释
            for marker in line_markers:
                start = line.find(marker, idx)
                if start != -1 and start < best_start:
                    best_start = start
                    found_marker_type = 'line'
                    found_marker = marker
            
            # 2. 查找最早的块注释
            for start_m, end_m in block_markers:
                start = line.find(start_m, idx)
                if start != -1 and start < best_start:
                    best_start = start
                    found_marker_type = 'block'
                    found_marker = (start_m, end_m)
            
            # 3. 根据找到的最早标记进行处理
            
            if found_marker_type is None:
                # 在 idx 之后没有找到任何注释，结束对这一行的处理
                break
            
            if found_marker_type == 'line':
                # 是行注释
                marker = found_marker
                content = line[best_start + len(marker):]
                print_comment(line_num, content)
                # 行注释会“吃掉”该行余下的所有内容，故直接 break
                break
            
            elif found_marker_type == 'block':
                # 是块注释
                start_marker, end_marker = found_marker
                start_of_content = best_start + len(start_marker)
                
                # 查找结束标记 (题目保证在同一行)
                end_of_content = line.find(end_marker, start_of_content)
                
                if end_of_content != -1:
                    content = line[start_of_content : end_of_content]
                    print_comment(line_num, content)
                    # 更新搜索位置，跳过这个块注释
                    idx = end_of_content + len(end_marker)
                else:
                    # 题目保证不会发生这种情况
                    # 为防止死循环，我们至少要移动 idx
                    idx = start_of_content

# --- 主程序 ---
# 题目没有说有多组测试数据 (T)，所以只调用一次 solve()
solve()