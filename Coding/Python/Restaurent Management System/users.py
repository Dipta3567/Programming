from abc import ABC
from orders import Order

class User(ABC):
    def __init__(self,name,phone,email,address) -> None:
        super().__init__()
        self.name=name
        self.phone=phone
        self.email=email
        self.address=address

class Admin(User):
    def __init__(self, name, phone, email, address) -> None:
        super().__init__(name, phone, email, address)
        
    def add_employee(self,restaurent,employee):
        restaurent.add_employee(employee)
    
    def view_employee(self,restaurent):
        restaurent.view_employee()
    def add_new_item(self,resturent,item):
        resturent.menu.add_menu_item(item)
    def remove_item(self,resturent,item):
        resturent.menu.remove_item(item)
    def view_items(self,resturent):
        resturent.menu.show_menu()


class Employee(User):
    def __init__(self, name, phone, email, address,age,designation,salary) -> None:
        super().__init__(name, phone, email, address)
        self.age=age
        self.designation=designation
        self.salary=salary

class Customer(User):
    def __init__(self, name, phone, email, address) -> None:
        super().__init__(name, phone, email, address)
        self.cart=Order()

    def view_menu(self,resturent):
        resturent.menu.show_menu()

    def add_to_cart(self,resturent,item_name,quantity):
        item=resturent.menu.find_item(item_name)
        if item:
            if int(quantity) > int(item.quantity):
                print("Item Quantity exceeded!!!")
            else:   
                #item.quantity=quantity
                #self.cart.add_item(item)
                self.cart.add_item(item,int(quantity))
                print("Item Added")
        else:
            print("Item Not Found")

    def view_cart(self):
        print("****View Cart****")
        print("Name\tPrice\tQuantity")
        for item,quantity in self.cart.items.items():
            print(f"{item.name}\t{item.price}\t{quantity}")
        print(f"Total price : {self.cart.total_price}")

    def pay_bill(self):
        print(f"Total Bill {self.cart.total_price} paid successfully")
        self.cart.clear()






    



""" 


****************************************This was for testing purpose***********************************

othiti=Restaurent("Othithi Resturent")
admin=Admin("Karim",12345,"Ales@hotmail.com","Dhaka")

item=FoodItem("Pizza",12.45,10)
item2=FoodItem("Burger",10,30)
admin.add_new_item(othiti,item)
admin.add_new_item(othiti,item2)




customer1=Customer("Rahim",1258765,"rahim@email.com","ctg")
customer1.view_menu(othiti)

item_name=input("Enter item name : ")
item_quantity=int(input("Enter Item Quantity : "))

customer1.add_to_cart(othiti,item_name,item_quantity)
customer1.view_cart() """


# emp=Employee("Rahim",123456,"rahim@gmail.com","Ctg",25,'Chef',12000)
# print(emp.age)


# ad=Admin("Karim",12345,"Ales@hotmail.com","Dhaka")
# ad.add_employee("sagor","Sa@gmail.com",159875,"CTG",32,"chef",12300)
# ad.view_employee()  


