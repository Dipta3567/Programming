def hcfnaive(a,b):
    if (b==0):
        return abs(a)
    else:
        return hcfnaive(b,a%b)
t=int(input())
for _ in range(t):
    a=int(input())
    print(a-1)
