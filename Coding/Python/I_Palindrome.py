x = input()
num = str(x)

flag = True
i = 0
j = -1
for _ in num:
    if num[i] != num[j]:
        flag = False
        break
    i += 1
    j -= 1

reverse_num=num[::-1].lstrip('0')
print(reverse_num)
if flag:
    print("YES")
else:
    print("NO")

    
