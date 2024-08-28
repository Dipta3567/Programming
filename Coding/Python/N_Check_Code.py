x,y=map(int,input().split())
st=input()
if len(st)!=x+y+1:
    print("No")
else:
    un=True
    nm1=True
    nm2=True
    for i in  range(0,x):
        if not st[i].isdigit():
            nm1=False
    for i in  range(x+1,x+y+1):
        if not st[i].isdigit():
            nm2=False
    if nm1 and nm2:
        if st[x]=='-':
            print("Yes")
        else:
            print("No")
    else:
        print("No")