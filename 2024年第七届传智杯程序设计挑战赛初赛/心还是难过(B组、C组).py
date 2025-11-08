s =input()
s1="-)"
s2="-("
count1 =s.count(s1)
count2 =s.count(s2)
if count1==0 and count2==0:
    print("None")
elif count1>count2:
    print("Happy")
elif count1<count2:
    print("Sad")
else:
    print("Just so so")