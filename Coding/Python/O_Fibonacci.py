pos=int(input())
x=0
y=1
if pos==1:
    print("0")
elif pos==2:
    print("1")
else:
    z=0
    for _ in range(3,pos+1):
        z=x+y
        x=y
        y=z
    print(f"{z}")