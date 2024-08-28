from users import Seller, Customer
from ProductItem import Product_Item
from shop import Shop
import time
import os
# Create a shop
Daraz = Shop("Daraz")

# Create some sellers
seller1 = Seller(name="Dipta", email="dipta@gmail.com", address="123 Main St", phone="555-555-5555", password="dipta@")
seller2 = Seller(name="Salman", email="salman@gmail.com", address="456 Maple Ave", phone="555-555-5556", password="salman@")

# Add the sellers to the shop
Daraz.Create_Seller_Account(seller1)
Daraz.Create_Seller_Account(seller2)

# Create some products
product1 = Product_Item(name="Iphone", price=100000, quan=10)
product2 = Product_Item(name="Samsung", price=80000, quan=20)
product3 = Product_Item(name="Macbook", price=70000, quan=30)
product4 = Product_Item(name="PC", price=50000, quan=40)

# Add the products to the sellers' product lists and the shop's shelf
seller1.add_product(Daraz, product1)
seller1.add_product(Daraz, product2)
seller2.add_product(Daraz, product3)
seller2.add_product(Daraz, product4)

# Create a customer
customer = Customer(name="saikat", email="saikat", address="789 Oak St", phone="555-555-5557", password="saikat")

# Add the customer to the shop
Daraz.Create_Customer_Account(customer)



#  Main menu




def customer_InterFace():
    print("1) Create New Account\n2)Login in Existing Account\n3)Exit")
    c=int(input("Enter Your Choice : "))
    if c==1:
        name=input("Enter Your Name : ")
        email=input("Enter Your Email : ")
        phone=input("Enter Your Phone : ")
        address=input("Enter Your Adress : ")
        while True:
            password=input("Create new password : ")
            repas=input("Re-Enter Password : ")
            if password==repas:
                break
        customer=Customer(name=name,email=email,address=address,phone=phone,password=password)
        if Daraz.Create_Customer_Account(customer):
            print("Account successfully created\n")
            time.sleep(1)
            os.system('cls')

            while True:
                print(f"Welcome {customer.name}")
                print("1. View Products")
                print("2. Add Product To Cart")
                print("3. View Cart")
                print("4. PayBill")
                print("5. Exit\n")

                choice=int(input("Enter Your Choice : "))
                if choice==1:
                    customer.view_Products(Daraz)
                elif choice ==2:
                    item_name=input("Enter Item Name : ")
                    item_quan=input("Input Item Quantity : ")
                    customer.add_to_cart(Daraz,item_name,item_quan)
                elif choice == 3:
                    customer.view_cart()
                elif choice == 4:
                    customer.pay_bill()
                elif choice == 5:
                    print("Thank you !!")
                    time.sleep(1)
                    os.system('cls')
                    break
                else:
                    print("Invalid")   
        else:
            print("User Existed\n")
            time.sleep(1)
            os.system('cls')

    elif c==2:
        email=input("Enter Your Email : ")
        password=input("Enter password : ")
        customer = Daraz.Customer_Login(email,password)
        if customer:
            while True:
                print(f"Welcome {customer.name}")
                print("1. View Products")
                print("2. Add Product To Cart")
                print("3. View Cart")
                print("4. PayBill")
                print("5. Exit\n")

                choice=int(input("Enter Your Choice : "))
                if choice==1:
                    customer.view_Products(Daraz)
                elif choice ==2:
                    item_name=input("Enter Item Name : ")
                    item_quan=input("Input Item Quantity : ")
                    customer.add_to_cart(Daraz,item_name,item_quan)
                elif choice == 3:
                    customer.view_cart()
                elif choice == 4:
                    customer.pay_bill()
                elif choice == 5:
                    print("Thank you !!")
                    time.sleep(1)
                    os.system('cls')
                    break
                else:
                    print("Invalid")
        else:
            print("Invalid Email or Password!!!!\n")
    elif c==3:
         print("Thank you !!")
         time.sleep(1)
         os.system('cls')
         return
    else:
        print("Invalid")




#------------------------------------------------------------------------

def seller_interface():
    print("1) Create New Account\n2)Login in Existing Account\n3)Exit")
    c=int(input("Enter Your Choice : "))
    if c==1:
        name=input("Enter Your Name : ")
        email=input("Enter Your Email : ")
        phone=input("Enter Your Phone : ")
        address=input("Enter Your Adress : ")
        while True:
            password=input("Create new password : ")
            repas=input("Re-Enter Password : ")
            if password==repas:
                break
        seller=Seller(name=name,email=email,address=address,phone=phone,password=password)
        if Daraz.Create_Seller_Account(seller):
            print("Account successfully created\n")
            time.sleep(1)
            os.system('cls')

            while True:
                print(f"Welcome {seller.name}")
                print("1. View Products")
                print("2. Add Product")
                print("3. Delete Product")
                print("4. Exit")

                choice=int(input("Enter Your Choice : "))
                if choice==1:
                    seller.view_product()
                elif choice ==2:
                    item_name=input("Enter Item Name : ")
                    item_quan=int(input("Input Item Quantity : "))
                    item_price=int(input("Input Item Price : "))
                    item=Product_Item(name=item_name,price=item_price,quan=item_quan)
                    seller.add_product(Daraz,item)
                elif choice == 3:
                    item_name=input("Enter Item Name : ")
                    seller.delete_product(Daraz,item_name)
                elif choice == 4:
                    print("Thank you !!")
                    time.sleep(1)
                    os.system('cls')
                    break
                else:
                    print("Invalid")   
        else:
            print("User Existed\n")
            time.sleep(1)
            os.system('cls')

    elif c==2:
        email=input("Enter Your Email : ")
        password=input("Enter password : ")
        seller = Daraz.Login_seller_account(email=email,passw=password)
        if seller:
            while True:
                print(f"Welcome {seller.name}")
                print("1. View Products")
                print("2. Add Product")
                print("3. Delete Product")
                print("4. Exit")

                choice=int(input("Enter Your Choice : "))
                if choice==1:
                    seller.view_product()
                elif choice ==2:
                    item_name=input("Enter Item Name : ")
                    item_quan=int(input("Input Item Quantity : "))
                    item_price=int(input("Input Item Price : "))
                    item=Product_Item(name=item_name,price=item_price,quan=item_quan)
                    seller.add_product(Daraz,item)
                elif choice == 3:
                    item_name=input("Enter Item Name : ")
                    seller.delete_product(Daraz,item_name)
                elif choice == 4:
                    print("Thank you !!")
                    time.sleep(1)
                    os.system('cls')
                    break
                else:
                    print("Invalid")   
        else:
            print("Invalid Email or Password!!!!\n")
    elif c==3:
         print("Thank you !!")
         time.sleep(1)
         os.system('cls')
         return
    else:
        print("Invalid")



while True:
    print("********Welcome******")
    print("1. Seller Panel")
    print("2. Customer Panel")
    print("3.Exit")
    choice=int(input("Enter Your Choice : "))

    if choice==1:
        os.system('cls')
        seller_interface()
    elif choice==2:
        os.system('cls')
        customer_InterFace()
    elif choice==3:
        break
    else:
        print("Invalid")
