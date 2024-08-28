t=int(input())
while t!=0:
    n=int(input())
    values=input()
    arr=[int(value) for value in values.split()]
    v=[]
    i=1
    for i in range(1,n+1):
        j=i+1
        for j in range(i+1,n+1):
            x=arr[j-1]+arr[i-1]+j-i
            v.append(x)
            j+=1
        i+=1
    print(f"{min(v)}")
    t-=1