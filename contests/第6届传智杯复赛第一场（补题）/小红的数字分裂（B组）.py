from functools import reduce
from math import gcd

def find_gcd(list_numbers):
    return reduce(lambda x,y:gcd(x,y),list_numbers)
a=int(input())
b =list(map(int,input().split()))
x=find_gcd(b)
sum =0
for num in b:
    sum+=(num//x)-1
print(sum)
# import math
# from math import gcd
# from functools import reduce

# def find_gcd(list_numbers):
#     return reduce(lambda x, y: gcd(x, y), list_numbers)

# def min_operations_to_equal_elements():
#     import sys
#     input = sys.stdin.read
#     data = input().split()
    
#     n = int(data[0])
#     arr = list(map(int, data[1:n+1]))
    
#     if n == 1:
#         print(0)
#         return
    
#     # 计算所有元素的GCD
#     x = find_gcd(arr)
    
#     # 计算总操作次数
#     total_operations = 0
#     for num in arr:
#         total_operations += (num // x) - 1
    
#     print(total_operations)

# if __name__ == "__main__":
#     min_operations_to_equal_elements()