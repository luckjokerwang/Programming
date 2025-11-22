n = int(input())
a = list(map(int, input().split()))

# 统计每个数字出现的次数
count = {}
for num in a:
    count[num] = count.get(num, 0) + 1

# 找出只出现一次的数字（赝品）
fakes = [num for num in count if count[num] == 1]
fakes.sort()  # 排序

# 输出结果
print(len(fakes))
print(' '.join(map(str, fakes)))