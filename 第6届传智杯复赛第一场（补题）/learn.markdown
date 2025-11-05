## enmerate
enumerate 是一个内置类，用于返回一个可迭代的枚举对象，该对象生成带有索引的元素对。

enumerate 常用于在遍历序列（如列表、字符串等）时同时获取元素及其索引。默认情况下，索引从 0 开始，但可通过 start 参数自定义起始值。

enumerate 是 Python 标准库中的一个内置类，定义于 builtins.pyi 类型存根文件中。它实现了迭代器协议，能够将任意可迭代对象包装成一个返回 (index, value) 元组的迭代器。
例如: 
```python
for index, value in enumerate(iterable, start=0):
    # 处理 index 和 value
```
## input().split()
input().split() 是 Python 中用于从标准输入读取一行字符串并将其拆分成列表的常用方法。
例如: 
```python
print(input().split())
# 输入: 1 2 3
# 输出: ['1', '2', '3']
```
注意:是input().split()而不是input.split()
因为input()是读取一行字符串，input().split()是读取一行字符串并将其拆分成列表。
## map
map 是 Python 中用于将一个函数应用于可迭代对象的内置函数。
例如: 
```python
print(list(map(int, input().split())))
# 输入: 1 2 3
# 输出: [1, 2, 3]
print(list(map(str, input().split())))
# 输入: 1 2 3
# 输出: ['1', '2', '3']
```
## 递归累加
```
from collections import defaultdict
count = defaultdict(int)
for num in a:
    count[num] += 1
```
```
for num in a:
    count[num] = count.get(num, 0) + 1
```
第一种效率更高
## reduce
reduce 是 Python 标准库中的一个内置函数，用于对可迭代对象中的元素进行**累积**操作。它接受两个参数：
1. 函数：用于累积操作的函数，该函数接受两个参数并返回一个值。
2. 可迭代对象：要累积操作的可迭代对象。
reduce 函数通过反复调用累积函数，将可迭代对象中的元素累积成一个单一的值。
例如: 
```python
from functools import reduce

# 计算列表中所有元素的乘积
def multiply(x, y):
    return x * y

result = reduce(multiply, [1, 2, 3, 4])
print(result)  # 输出: 24

# 计算列表中所有元素的和
def add(x, y):
    return x + y

result = reduce(add, [1, 2, 3, 4])
print(result)  # 输出: 10
```
## get(key,default)
get(key,default) 是 Python 字典（dict）中的一个方法，用于获取指定键的值。如果键存在于字典中，则返回对应的值；如果键不存在，则返回默认值（default）。
例如: 
```python
dict = {'a': 1, 'b': 2, 'c': 3}
print(dict.get('a'))  # 输出: 1
print(dict.get('d', 0))  # 输出: 0
```

## ord
ord() 是 Python 内置函数，用于返回字符的 Unicode 码点值。
例如: 
```python
print(ord('a'))  # 输出: 97
print(ord('A'))  # 输出: 65
```

## mod 要注意范围和条件