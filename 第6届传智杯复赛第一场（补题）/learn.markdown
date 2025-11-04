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

