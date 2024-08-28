from Bank import Bank
from transaction import Transaction
from user import Admin,Customer
import os
import time

ab=Bank("AB")

def admin_system(admin):
    while True:
        print(f"\n\nWelcome {admin.name}")
        print("1) create an account")
        print("2) Delete User Account")
        print("3) All User Account List")
        print("4) Check Total Available Bank Balance")
        print("5) Check Total Loan amount")
        print("6) Loan Feature Permision")
        print("7) WithDraw Permission")
        print("8) Exit")
                
        choice=int(input("Enter Your choice : "))

        if choice==1:
            name=input("Enter Your Name : ")
            email=input("Enter Your Email : ")
            phone=input("Enter Your Phone : ")
            address=input("Enter Your Address : ")
            while True:
                print("Account Type : 1. Savings  2. Cuurent")
                op=int(input("Enter Your Choice : "))
                if op==1:
                    typ="Savings"
                    break
                elif op==2:
                    typ="Cuurent"
                    break
                else:
                    print("Invalid\n")

            while True:
                password=input("Create new password : ")
                repas=input("Re-Enter Password : ")
                if password==repas:
                    break
            customer=Customer(name=name,email=email,phone=phone,password=password,account_type=typ,address=address)
            admin.create_user_account(ab,customer)
            print("Account Successfully Created")
                
        elif choice==2:
            account=int(input("Enter User Account Number : "))
            admin.delete_user_account(ab,account)
        elif choice==3:
            admin.list_users(ab)

        elif choice==4:
            admin.check_balance(ab)

        elif choice==5:
            admin.check_loan(ab)

        elif choice==6:
            print("1) Bank Loan Feature\n2) User Loan Feature")
            opt=int(input("Enter Your choice : "))
            if opt==1:
                admin.bank_loan_feature(ab)
            elif opt==2:
                account=int(input("Enter User Account Number : "))
                admin.loan_feature(ab,account)
        elif choice==7:
            admin.withdraw_permission(ab)

        elif choice==8:
            print("Bye Bye.....")
            time.sleep(1)
            os.system('cls')
            break
        else:
            print("Invalid\n")
    return



def admin_interface():
    print("1) Create New Account\n2)Login in Existing Account\n3)Exit")
    c=int(input("Enter Your Choice : "))
    if c==1:
        name=input("Enter Your Name : ")
        email=input("Enter Your Email : ")
        phone=input("Enter Your Phone : ")
        address=input("Enter Your Address : ")
        while True:
            password=input("Create new password : ")
            repas=input("Re-Enter Password : ")
            if password==repas:
                break
        admin=Admin(name=name,email=email,phone=phone,password=password,address=address)
        if ab.add_admin(admin):
            print("Admin account has benn created")
            time.sleep(1)
            os.system('cls')
            admin_system(admin)
    elif c==2:
        email=input("Enter Your Email : ")
        password=input("Enter password : ")
        admin=ab.login_admin(email,password)
        if admin:
            print("Login Successfully....")
            time.sleep(1)
            os.system('cls')
            admin_system(admin)
        else:
            print("Admin not found!!!")
    elif c==3:
        print("Thank you !!")
        time.sleep(1)
        os.system('cls')
        return
    else:
        print("Invalid")


def user_system(customer):
    while True:
        print(f"\n\nWelcome {customer.name} To {ab.name} Bank\n")
        print("1.Deposit amount")
        print("2.Withdraw amount")
        print("3.Transfer amount")
        print("4.Take Loan")
        print("5.Pay Loan")
        print("6.Check balance")
        print("7.Check Transaction")
        print("8.Exit")

        choice=int(input("Enter Your choice : "))
        if choice==1:
            while True:
                amount=int(input("Enter The Amount : "))
                if amount<=0:
                    print("Invalid Amount\n")
                else:
                    break
            customer.deposit(amount)
        elif choice==2:
            if ab.withdraw_permision==True:
                while True:
                    amount=int(input("Enter The Amount : "))
                    if amount<=0:
                        print("Invalid Amount\n")
                    else:
                        break
                customer.withdraw(amount)
            else:
                print(f"{ab.name} Bank has gone BANKRUPT!!!!!!!")
        elif choice==3:
            while True:
                account=int(input("Enter The Receiver Account Number : "))
                if account==customer.account:
                    print("Receiver Account can not be sender account\n")
                else:
                    break
            while True:
                amount=int(input("Enter The Amount : "))
                if amount<=0:
                    print("Invalid Amount\n")
                else:
                    break
            customer.transfer_balance(amount=amount,account=account,bank=ab)
        elif choice==4:
            if ab.loan_permision==True:
                if customer.loan_permission==True:
                    while True:
                        amount=int(input("Enter The Amount : "))
                        if amount<=0:
                            print("Enter Amount Correctly\n")
                        else:
                            break

                    customer.take_loan(amount=amount)
                else:
                    print("You are not eligible for loan. Contact Bank for further inquire")
            else:
                print(f"{ab.name} Bank has stop Loan Providing Service")
        elif choice==5:
            if customer.loan==0:
                print("You Don't Owe Any Loan")
            else:
                while True:
                    amount=int(input("Enter The Amount : "))
                    if amount<=0:
                        print("Invalid Amount\n")
                    else:
                        break
                customer.pay_loan(amount)
        elif choice==6:
            customer.check_balance()
        elif choice==7:
            print("\n")
            customer.check_transaction(ab)
        elif choice==8:
            print("Bye Bye.....")
            time.sleep(1)
            os.system('cls')
            break
        else:
            print("Invalid\n")
    return
        
def customer_interface():
    print("1) Create New Account\n2)Login in Existing Account\n3)Exit")
    c=int(input("Enter Your Choice : "))
    if c==1:
        name=input("Enter Your Name : ")
        email=input("Enter Your Email : ")
        phone=input("Enter Your Phone : ")
        address=input("Enter Your Address : ")
        while True:
            print("Account Type : 1. Savings  2. Cuurent")
            op=int(input("Enter Your Choice : "))
            if op==1:
                typ="Savings"
                break
            elif op==2:
                typ="Cuurent"
                break
            else:
                print("Invalid\n")

        while True:
            password=input("Create new password : ")
            repas=input("Re-Enter Password : ")
            if password==repas:
                break
        customer=Customer(name=name,email=email,phone=phone,password=password,account_type=typ,address=address)
        ab.add_customer(customer)
        print("Account Successfully Created")
        time.sleep(1)
        os.system('cls')
        user_system(customer)

    elif c==2:
        email=input("Enter Your Email : ")
        password=input("Enter password : ")
        customer=ab.login_user(email=email,passw=password)
        if customer:
            print("Login Successfully....")
            time.sleep(1)
            os.system('cls')
            user_system(customer)
        else:
              print("User not found!!!")

    elif c==3:
        print("Thank you !!")
        time.sleep(1)
        os.system('cls')
        return
    else:
        print("Invalid")



# for test

admin = Admin(name="Dipta", email="dipta@", phone="1234567890", password="dipta",address="Dhaka")
ab.add_admin(admin)

customer1 = Customer(name="Salman", email="salman@", phone="0987654321", password="salman", account_type="Savings",address="CTG")
admin.create_user_account(ab, customer1)

customer2 = Customer(name="Saikat", email="saikat@", phone="0987654322", password="saikat", account_type="Savings",address="Dhaka")
admin.create_user_account(ab, customer2)

customer3 = Customer(name="Shahariar", email="shahariar", phone="0987654323", password="shahariar", account_type="Cuurent",address="Rajshahi")
admin.create_user_account(ab, customer3)

customer4 = Customer(name="Imam", email="imam@", phone="0987654324", password="imam", account_type="Savings",address="Khulna")
admin.create_user_account(ab, customer4)

customer5 = Customer(name="Tazbih", email="tazbih@", phone="0987654325", password="tazbih", account_type="Savings",address="CTG")
admin.create_user_account(ab, customer5)



while True:
    print(f"********Welcome To {ab.name} Bank******")
    print("1. Admin Panel")
    print("2. Customer Panel")
    print("3.Exit")
    choice=int(input("Enter Your Choice : "))

    if choice==1:
        os.system('cls')
        admin_interface()
    elif choice==2:
        os.system('cls')
        customer_interface()
    elif choice==3:
        break
    else:
        print("Invalid")

        
            
                

        

