from itertools import accumulate


n,t=map(int,input().split())
arr=input()
v=[int(val) for val in arr.split()]
sum=list(accumulate(v))



""" for i in range(0,n):
    if i==0:
        sum.append(v[0])
    else:
        sum.append(sum[i-1]+v[i])
    i+=1 """
while t!=0:
    l,r=map(int,input().split())
    l-=1
    r-=1
    if l==0:
        print(sum[r])
    else:
        print(sum[r]-sum[l-1])
    t-=1