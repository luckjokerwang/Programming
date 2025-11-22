import sys
data =list(map(int,sys.stdin.buffer.read().split()))
n =data[0]

for i in range(1,2*n+1,2):
    k=data[i]//data[i+1]
    p=data[i]%data[i+1]
    print(f"{data[i]}={k}*{data[i+1]}+{p}")
    
    