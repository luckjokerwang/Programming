a=str(input())
b = len(a)
if b%3==0:
    for index,i in enumerate(a):
        print(i,end="")
        if(index+1 ==b*2/3):
            print(end=" ")
else:
    print(-1)