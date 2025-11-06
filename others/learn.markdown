## sys.stdin.buffer.read().split()
解释:
    1. sys.stdin.buffer.read() 读取输入的全部内容，返回一个字节字符串
    2. .split() 将字节字符串按空格分割成列表
    3. map(int, ... ) 将列表中的每个元素转换为整数
    4. list(... ) 将map对象转换为列表
例子:
```
a=list(map(int,sys.stdin.buffer.read().split()))

    输入:
    5
    1 2 3 4 5
    输出:
    [5, 1, 2, 3, 4, 5]
```

## range(start,stop,step)
例子:
```
for i in range(1,5,2):
    print(i)
输出:
1
3
//range(start,stop,step)的step可以为负数
for i in range(5,1,-2):
    print(i)
输出:
5
3
1
```
## bisect
原理:二分查找
解释:
    1. bisect.bisect(a,x) 返回x在a中的插入位置
例子:
```
import bisect
a=[1,2,3,3,4,5]
bisect.bisect(a,3)
输出:
4
bisect.bisect_left(a,3)//bisect 是 bisect_right 的别名
输出:
2
bisect.bisect_right(a,3)
输出:
4
bisect.insort(a,3)
输出:
[1, 2, 3, 3,3, 4, 5]
```
## LIS与LSD
模板:
```
lis=[0]*n
tails =[]
for i,x in enumerate(a):
    pos = bisect.bisect_right(tails,x)
    if pos == len(tails):
        tails.append(x)
    else:
        tails[pos]=x
    lis[i]=pos+1
```
lsd可以看成是lis的逆序,即反向输出
lsd模板:
``` 
lds=[0]*n
tails =[]
for i in range(n-1,-1,-1):
    x =a[i]
    pos =bisect.bisect_right(tails,x)
    if pos ==len(tails):
        tails.append(x)
    else:
        tails[pos] =x    
    lds[i] =pos+1
```
