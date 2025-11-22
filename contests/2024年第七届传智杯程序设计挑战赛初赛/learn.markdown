## sort sorted
sort()是列表方法，sorted()是内置函数
sort()会修改原列表，sorted()不会修改原列表
举例:
```python
a = [1,2,3,4,5]
b = sorted(a)
print(a)
print(b)
a.sort()
print(a)
print(b)
```
## list(map(int,sys.stdin.read().split()))
标准化输出所有数据
```python
import sys
data = list(map(int,sys.stdin.read().split()))
print(data)
```

## join
join 是字符串类 str 的一个方法，用于将可迭代对象中的字符串元素连接成一个新字符串。**
该方法属于 Python 内置类型 str，定义在标准库的类型存根文件中，用于类型检查工具（如 Pyright）推断正确的行为和返回类型。

举例:
```python
a = ['1','2','3','4','5']
b = ''.join(a)
print(b)
# 输出: 12345
```

## count
定义
count 是 str 类的一个实例方法，定义于 Python 标准库的类型存根文件中（builtins.pyi），用于计算某个子字符串在原字符串中非重叠匹配的次数。可选地，可以通过 start 和 end 参数限制搜索范围，其解释方式与切片（slice notation）一致。
举例:
```python
s = 'hello world'
count = s.count('l')
print(count)
# 输出: 3
```

### 3. 优先队列（Priority Queue）
优先队列是一种特殊的队列，元素按照优先级出队，而不是按照入队顺序。Python 中可以使用 `heapq` 模块实现优先队列。

#### 实现方式
```python
import heapq

class PriorityQueue:
    def __init__(self):
        self._queue = []
        self._index = 0  # 用于处理优先级相同的元素

    def push(self, item, priority):
        # 堆是最小堆，所以用 -priority 实现最大堆
        heapq.heappush(self._queue, (-priority, self._index, item))
        self._index += 1

    def pop(self):
        return heapq.heappop(self._queue)[-1]  # 返回 item

# 使用示例
pq = PriorityQueue()
pq.push('task1', 3)  # 优先级 3
pq.push('task2', 1)  # 优先级 1
pq.push('task3', 2)  # 优先级 2

print(pq.pop())  # 输出: task1（优先级最高）
print(pq.pop())  # 输出: task3
print(pq.pop())  # 输出: task2
```

#### 特点
- **时间复杂度**：
  - 入队：O(log n)
  - 出队：O(log n)
  - 查看队首：O(1)
- **用途**：
  - 任务调度
  - Dijkstra 算法
  - 哈夫曼编码

### 4. 队列与优先队列对比
| 特性       | 队列 (Queue)          | 优先队列 (Priority Queue)  |
|------------|-----------------------|---------------------------|
| 出队顺序   | 先进先出 (FIFO)       | 按优先级出队              |
| 实现方式   | `collections.deque`   | `heapq` 模块             |
| 时间复杂度 | 入队/出队 O(1)        | 入队/出队 O(log n)        |
| 典型应用   | BFS、缓存、消息队列   | 任务调度、最短路径算法    |

### 5. 示例：使用优先队列解决 Top K 问题
```python
import heapq

def top_k_elements(nums, k):
    # 使用最小堆保存前 K 大的元素
    min_heap = []
    for num in nums:
        if len(min_heap) < k:
            heapq.heappush(min_heap, num)
        elif num > min_heap[0]:
            heapq.heappop(min_heap)
            heapq.heappush(min_heap, num)
    return min_heap

nums = [3, 1, 4, 1, 5, 9, 2, 6]
print(top_k_elements(nums, 3))  # 输出: [4, 5, 6]（前 3 大的数）
```

### 6. 总结
- **队列**：适合需要严格 FIFO 的场景，如 BFS。
- **优先队列**：适合需要按优先级处理元素的场景，如任务调度、贪心算法。

根据你的需求选择合适的队列类型！