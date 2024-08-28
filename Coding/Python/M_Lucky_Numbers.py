x,y=map(int,input().split())

list=[]

for i in range (x,y+1):
    
        tmp=i
        flag=True
        while tmp!=0 :
            a=tmp%10
            tmp=tmp//10
            if a!=4 and a!=7:
                flag=False
        if flag:
            list.append(i)

if len(list)==0:
    print('-1')
else:
    for i in list:
        print(i,end=" ")