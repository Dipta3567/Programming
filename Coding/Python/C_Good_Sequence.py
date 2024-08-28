n=int(input())
v=input()
arr=[int(val) for val in v.split()]
cnt=0
myset={}
for i in range(0,n):
    myset[arr[i]]=myset.get(arr[i],0)+1
for u in myset.items():
    if u[1]>=u[0]:
        cnt+=(u[1]-u[0])
    else:
        cnt+=u[1]
print(f'{cnt}')