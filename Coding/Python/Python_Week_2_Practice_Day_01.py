from pyclbr import Class


class Shop:
    
    def __init__(self,Name,Adress,Number) -> None:
        self.Name=Name
        self.Adress=Adress
        self.Number=Number
        self.products=[] # Store Products in the shop

    def add_product(self,Product):
        self.products.append(Product)

    def buy_product(self,product):
        if product in self.products:
            self.products.remove(product)
            return "Congrats! You have successfully bought the product."
        else:
            return "sorry, this product is not available."

    def __repr__(self) -> str:
        return f'Shop Name: {self.Name}\nShop Adress: {self.Adress}\nContact Number: {self.Number}\n'

class Product():

    def __init__(self,Name,Price) -> None:
        self.name=Name
        self.price=Price

    def __repr__(self) -> str:
        return f'Product Name : {self.name}\nPrice : {self.price}\n'
print("\n")    
product1=Product("Apple",230)
product2=Product("Banana",100)

shop=Shop('Fruit Shop', 'Colllege Road','123456789')

shop.add_product(product1)
shop.add_product(product2)

print(shop.buy_product(product1))

print(shop)

print("Shop's Product : ")
for product in shop.products:
    print(product)








""" 

4) What is Inheritance? Explain with examples

Inheritance is one of the core features of object-oriented programming. It allows you to create a new class from an existing class. The new class that is created is known as a subclass (child or derived class), and the existing class from where the child class is derived is known as a superclass (parent or base class)1.

Inheritance is an “is-a” relationship. For example, a Dog is an Animal, so Dog can inherit from Animal. Here’s a simple example in Python:

Code: 
"""

class Animal:
    def __init__(self,name) -> None:
        self.name=name

    def eat(self):
        print(f"{self.name} is eating")
class Dog(Animal):
    def bark(self):
        print(f"{self.name} is barking.")

mydog=Dog("Rex")
mydog.eat()
mydog.bark()


""" 

5) What are Encapsulation and Access Modifiers? Explain with examples

Encapsulation is one of the fundamental concepts in object-oriented programming (OOP). It refers to the bundling of data, and the methods that operate on that data, into a single unit called a class. Encapsulation can be seen as a protective barrier that prevents the data being accessed directly from outside the class. It can only be accessed through the methods present inside the class

Access Modifiers are keywords in object-oriented languages that set the accessibility of classes, interfaces, and other members. Access modifiers define the scope and visibility of a class member.
There are typically four types of access modifiers:

Public: The members (variables, methods, etc) declared public can be accessed from anywhere.
Private: The members declared private can't be seen outside of the class. They can be accessed only from within the class.
Protected: The members declared protected can be accessed from within the class and its subclasses.
Default: If no access modifier is specified, then it behaves as default. Default members can be accessed only within the same package

Example: 
"""

class BankAccount:
    def __init__(self) -> None:
        self.__balance=0 # Private attribute


    def deposit(self,amount): # Public method
        self.__balance+=amount
        return self.__balance
    
    def withdraw(self,amount): # Public Method
        if amount >self.__balance:
            print("Insufficient balance!")
        else:
            self.__balance-=amount
            return self.__balance