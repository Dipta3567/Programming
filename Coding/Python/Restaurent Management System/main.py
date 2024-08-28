from random import choice
from Food_Item import FoodItem
from Menu import Menu
from users import Admin,Employee,Customer
from Resturent import Restaurent
from orders import Order
import os
import time

Mamar_Resturent=Restaurent("Mamar Resturent")

def customer_interface():
    name=input("Enter Your Name : ")
    email=input("Enter Your Email : ")
    phone=input("Enter Your Phone : ")
    address=input("Enter Your Adress : ")
    customer=Customer(name=name,email=email,phone=phone,address=address)

    while True:
        print(f"Welcome {customer.name}")
        print("1. View Menu")
        print("2. Add Item To Cart")
        print("3. View Cart")
        print("4. PayBill")
        print("5. Exit\n")

        choice=int(input("Enter Your Choice : "))
        if choice==1:
            customer.view_menu(Mamar_Resturent)
        elif choice==2:
            item_name=input("Enter Item Name : ")
            item_quan=input("Input Item Quantity : ")
            customer.add_to_cart(Mamar_Resturent,item_name,item_quan)
        elif choice==3:
              customer.view_cart()
        elif choice==4:
            customer.pay_bill()
        elif choice==5:
            print("Thank you !!")
            time.sleep(1)
            os.system('cls')
            break
        else:
            print("Invalid")



def Admin_interface():
    ad_name=input("Enter Your Name : ")
    ad_email=input("Enter Your Email : ")
    ad_phone=input("Enter Your Phone : ")
    ad_address=input("Enter Your Adress : ")
    admin=Admin(name=ad_name,email=ad_email,phone=ad_phone,address=ad_address)

    while True:
        print(f"Welcome {admin.name}")
        print("1. Add New Item")
        print("2. Add New Employee")
        print("3. View Employee")
        print("4. View Items")
        print("5. Delete Item")
        print("6. Log Out\n")

        choice=int(input("Enter Your Choice : "))
        if choice==1:
            item_name=input("Enter Item Name : ")
            item_price=int(input("Enter Item Price : "))
            item_quan=input("Input Item Quantity : ")
            item=FoodItem(item_name,item_price,item_quan)
            admin.add_new_item(Mamar_Resturent,item)
        elif choice==2:
            name=input("Enter Employee Name : ")
            phone=input("Enter Employee Phone : ")
            email=input("Enter Employee Email : ")
            address=input("Enter Employee Address : ")
            age=input("Enter Employee Age : ")
            designation=input("Enter Employee Designation : ")
            salary=int(input("Enter Employee Salary : "))

            employee=Employee(name=name,phone=phone,email=email,address=address,age=age,designation=designation,salary=salary)
            admin.add_employee(Mamar_Resturent,employee)

        elif choice==3:
              admin.view_employee(Mamar_Resturent)
        elif choice==4:
            admin.view_items(Mamar_Resturent)
        elif choice==5:
            item_name=input("Enter Item Name : ")
            admin.remove_item(Mamar_Resturent,item_name)
        elif choice==6:
            print(f"Log Out successfull!!\nBye {admin.name} !!!!")
            time.sleep(1)
            os.system('cls')
            break
        else:
            print("Invalid")

while True:
    print("********Welcome******")
    print("1. Admin Login")
    print("2. Customer Login")
    print("3.Exit")
    choice=int(input("Enter Your Choice : "))

    if choice==1:
        os.system('cls')
        Admin_interface()
    elif choice==2:
        os.system('cls')
        customer_interface()
    elif choice==3:
        break
    else:
        print("Invalid")



