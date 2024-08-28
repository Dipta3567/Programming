n=int(input())
v=input()
arr=[int(val) for val in v.split()]
cnt=0
while 1:
    if all(x%2==0 for x in arr):
        cnt+=1
        for u in range(0,n):
            arr[u]=arr[u]//2
    else:
        break
print(f'{cnt}')
