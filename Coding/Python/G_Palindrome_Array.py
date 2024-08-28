n=int(input())
values=input()
arr=[int(value) for value in values.split()]
flag=True
i=0
j=-1
for _ in arr:
    if arr[i]!=arr[j]:
        flag=False
        break
    i+=1
    j-=1
if flag:
    print('YES')
else:
    print("NO")