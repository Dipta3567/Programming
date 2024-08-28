def minMax(arr):
    minvalue=arr.index(min(arr))
    maxvalue=arr.index(max(arr))
    arr[minvalue],arr[maxvalue]=arr[maxvalue],arr[minvalue]
    return arr

n=int(input())
arr=[]
values=input()
arr=[int(value) for value in values.split()]
minMax(arr)
for i in arr:
    print(i,end=" ")
