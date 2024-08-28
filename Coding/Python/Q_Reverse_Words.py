
s=input()
word=''
lens=len(s)
for i in range(lens):
    if s[i].isalpha():
        word+=s[i]
        if i+1==lens:
            print(word[::-1])
            word=''
        elif not s[i+1].isalpha():
            print(word[::-1],end=" ")
            word=''
        