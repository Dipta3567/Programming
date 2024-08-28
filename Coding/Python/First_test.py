from operator import truediv


print("Hello World")

age = 45
is_single = True
print(age)
print(is_single)
district = "ctg"
""" 

 Ctrl + / = comment

 Alt + Shift + A = multiline comment

 """
print(type(age))

print("Kodom ali" + " Kacha badam")
text = f"kodom ali ki {age} living in {district}"
# akane value gula print er jonno f use korse. f use na korle ata pura tai string hoi jabe
print(text)


# Input and Output and Typecasting in python

print("I need money")
input()

money = input("I need money : ")
print("Here is your money", money)


first_Money = input("Kodom ali give me :")
second_money = input("Salamn giver me : ")
total = int(first_Money) + int(second_money)
print(
    "Total Money :", total
)  # ata string concat kore felse fix korar jonno typecasting kora lagbe


# Basic Operators and comparison

num1 = 45
num2 = 7
print(num1 + num2)
print(num1 - num2)
print(num1 * num2)
print(num1 / num2)
print(num1 % num2)

# / korar por doshomik gula bad deya lagle

print(10 // 3)
num1 = 45
num2 = 7
print(num1**num2)


# Conditional Statement in python

if num1 > num2:
    print("Yes")
elif num1 == num2:
    print("Same")
else:
    print("No")

boss = True

if boss is True:
    print("Tel")
else:
    print("No")





# while loop in python

num=1
while num < 10 :
    print("Hello this is",num,end=' ')
    num+=1


# for loop

numbers=[10,20,30,40,50,60]

for nami in numbers:
    print(nami)


for i in range(1,10,2):
    print(i)


x = 5
y = 3
print(x % y)

for i in range(5):
    print(i)
