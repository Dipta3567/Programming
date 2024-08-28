# function declare korar jonno def use kora hoi
def double (num):
    return num**2
    


def sum(x,y):
    return x+y

print("Total :",double(sum(10,20)))


# (advanced) kargs, multiple return from a function

def famous(first,last,**adition):
    name=f'{first} {last}'
    for key,value in adition.items():
        print(key +' : '+ value)
    return name
name=famous(first='Dipta', last='Dhor', title='Hacker', title1='Of the world')
print(name)


#local and global scope in python
balance=3000

def buy_things(item,price):
    
    print ('balace inside the function', balance)

buy_things('sunglass',1000)


