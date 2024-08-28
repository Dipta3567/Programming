"""

1) Write what is meant by operator overloading and method overriding with examples.

class Person:
    def __init__(self, name, age, height, weight) -> None:
        self.name = name
        self.age = age
        self.height = height
        self.weight = weight

class Cricketer(Person):
    def __init__(self, name, age, height, weight) -> None:
        super().__init__(name, age, height, weight)

sakib = Cricketer('Sakib', 38, 68, 91)
musfiq = Cricketer('Rahim', 36, 68, 88)
kamal = Cricketer('Kamal', 39, 68, 94)
jack = Cricketer('Jack', 38, 68, 91)
kalam = Cricketer('Kalam', 37, 68, 95)




Ans: 
Operator Overloading: Operator overloading allows you to redefine the meaning of an operator (like +, -, *, /)
for custom classes in Python. This can make your code more intuitive and easy to read.
Here’s an example of operator overloading with the + operator for a custom Vector class:


In this example, we’ve overloaded the + operator to add two Vector objects together.
 """
class Vector:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, other):
        return Vector(self.x + other.x, self.y + other.y)

v1 = Vector(2, 3)
v2 = Vector(1, 4)
v3 = v1 + v2  # This calls the __add__ method
print(v3.x, v3.y)  # Output: 3 7



"""

Method Overriding: Method overriding is a feature of Object-oriented programming that allows a subclass to provide a different implementation of a method that is already defined in its superclass. It is used to change the behavior of existing methods to suit the needs of the object.

In your provided code, the __init__ method in the Cricketer class is an example of method overriding. The Cricketer class is a subclass of the Person class and it provides its own implementation of the __init__ method:


In this example, the Cricketer class overrides the __init__ method of the Person class. It still calls the Person class’s __init__ method using the super() function, but it could add additional functionality if needed. This is a basic example of method overriding.
 """
class Person:
    def __init__(self, name, age, height, weight):
        self.name = name
        self.age = age
        self.height = height
        self.weight = weight

class Cricketer(Person):
    def __init__(self, name, age, height, weight):
        super().__init__(name, age, height, weight)  # Calls the __init__ method in the Person class

sakib = Cricketer('Sakib', 38, 68, 91)




#2


class Person:
    def __init__(self, name, age, height, weight) -> None:
        self.name = name
        self.age = age
        self.height = height
        self.weight = weight

class Cricketer(Person):
    def __init__(self, name, age, height, weight) -> None:
        super().__init__(name, age, height, weight)
    def __gt__(self,other):
        return self.age > other.age



sakib = Cricketer('Sakib', 38, 68, 91)
musfiq = Cricketer('Rahim', 36, 68, 88)
kamal = Cricketer('Kamal', 39, 68, 94)
jack = Cricketer('Jack', 38, 68, 91)
kalam = Cricketer('Kalam', 37, 68, 95)

arr=[sakib,musfiq,kamal,jack,kalam]


older=max(arr)
print(f"The Olderst cricketer is {older.name} whose age is {older.age}")


"""

3) Write down 4 differences between the class method and static method with proper examples.
Ans:

Definition:

Class Method: A class method is a method that's bound to the class and not the instance of the class. They have access to the state of the class as it takes a class parameter that points to the class and not the instance of the object.
Static Method: A static method doesn't take any specific parameters. It can't access or modify class state. It is present in a class because it makes sense for the method to be present in class.

Decorator:

Class Method: Class methods are marked with the @classmethod decorator.
Static Method: Static methods are marked with the @staticmethod decorator.

Parameters:

Class Method: The first parameter of a class method is a reference to the class, commonly named cls.
Static Method: Static methods do not have a special first parameter.

Usage:

Class Method: Class methods can modify the class state that would apply across all instances of the class. They can also be overridden by subclasses.
Static Method: Static methods behave like plain functions, except for the fact that you can call them from an instance of the class.

Here are examples of class methods and static methods:

 """
class MyClass:
    class_var = 0

    @classmethod
    def class_method(cls):
        cls.class_var += 1  # Can modify class variable

    @staticmethod
    def static_method(x, y):
        return x + y  # Can't access or modify class variable

# Using class method
MyClass.class_method()
print(MyClass.class_var)  # Output: 1, class variable has been modified

# Using static method
result = MyClass.static_method(10, 20)
print(result)  # Output: 30, it's just a function performing an operation


"""

4) Write what are getter and setter with proper examples

Ans: 

In object-oriented programming, getters and setters are methods that control access to an object’s attributes. They provide a way to change the values of an object’s instance variables without directly manipulating them.

Getter: A getter method is used to read the value of a private variable. It is a way of accessing the value of a variable outside of the class.
Setter: A setter method is used to set the value of a private variable. It is a way of changing the value of a variable outside of the class.
Here’s an example in Python using the @property decorator for the getter and @<variable>.setter decorator for the setter:

 """

# Define a class named Person
class Person:
    # Initialize the Person class with a name attribute
    def __init__(self, name=None):
        self._name = name  # Set the name attribute

    # Define a getter for the name attribute
    @property
    def name(self):
        return self._name  # Return the value of the name attribute

    # Define a setter for the name attribute
    @name.setter
    def name(self, value):
        # Check if the value is a string
        if not isinstance(value, str):
            # If the value is not a string, raise a ValueError
            raise ValueError("Name must be a string.")
        # If the value is a string, set the name attribute
        self._name = value

# Create an instance of the Person class
p = Person()
# Use the setter to set the name attribute
p.name = "Alice"
# Use the getter to get the value of the name attribute
print(p.name)


"""
5) Explain the difference between inheritance and composition with proper examples.
Ans:
Inheritance is a mechanism where you can derive a class from another class for a hierarchy of classes that share a set of attributes and methods. The child class, also known as derived class, inherits the members of the parent class, also known as base class. This allows code reusability.

Here's an example of inheritance:
 """
# Base class
class Animal:
    def __init__(self, name):
        self.name = name

    def speak(self):
        pass

# Derived class
class Dog(Animal):
    def speak(self):
        return "Woof!"

# Usage
d = Dog("Fido")
print(d.name)  # Output: Fido
print(d.speak())  # Output: Woof!

"""
Composition, on the other hand, is a way to combine simple objects or data types into more complex ones. Composition allows a class to contain an instance of another class. It’s often used when one object is part of another object.

Here's an example of composition:
 """

class Engine:
    def __init__(self, power):
        self.power = power

class Car:
    def __init__(self, color, power):
        self.color = color
        self.engine = Engine(power)

# Usage
c = Car("red", 200)
print(c.color)  # Output: red
print(c.engine.power)  # Output: 200

"""
In summary, the main differences between inheritance and composition are:

Inheritance represents an “is-a” relationship. For example, a Dog is an Animal.
Composition represents a “has-a” relationship. For example, a Car has an Engine.
Inheritance is useful for code reusability and representing real-world relationships between classes.
Composition is useful for creating complex types by combining objects, and gives you a lot of flexibility in how you structure your code. It's often a good choice when one object is a part of another object.

 """