s = input().strip()

def is_valid(s: str) -> bool:
    # 如果字符串长度为奇数，直接返回False
    if len(s) % 2 != 0:
        return False
    
    stack = []
    # 使用字典存储右括号对应的左括号
    mapping = {')': '(', ']': '[', '}': '{'}
    
    for char in s:
        if char in mapping:  # 如果是右括号
            # 栈顶元素出栈，如果栈为空则使用一个特殊字符
            top_element = stack.pop() if stack else '#'
            # 检查是否匹配
            if mapping[char] != top_element:
                return False
        else:  # 如果是左括号，压入栈中
            stack.append(char)
    
    # 如果栈为空，说明所有括号都匹配成功
    return not stack

# 输出结果
print("Yes" if is_valid(s) else "No")