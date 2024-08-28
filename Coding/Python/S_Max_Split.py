s=input()
arr=[]
cnt=0
word=''
cnt_r=0
cnt_l=0
for i in range(len(s)):
    word+=s[i]
    if s[i]=='R':
        cnt_r+=1
    else:
        cnt_l+=1
    if cnt_r==cnt_l:
        arr.append(word)
        word=''
        cnt+=1

print(f'{cnt}')
for i in arr:
    print(i)
