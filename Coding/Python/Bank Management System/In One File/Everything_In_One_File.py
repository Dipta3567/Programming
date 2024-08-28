from datetime import datetime
from abc import ABC
import random
import string
from datetime import datetime
import os
import time

class Bank:
    def __init__(self,Name) -> None:
        self.name=Name
        self.admins=[]
        self.users=[]
        self.loan_permision=True
        self.withdraw_permision=True

    def add_admin(self,admin):
        if admin in self.admins:
            return False
        else:
            self.admins.append(admin)
            return True
        
    def login_admin(self,email,passw):
        if not self.admins:
            print("There are no Admin\n")
            return False
        for admin in self.admins:
            if admin.email==email and admin.password==passw:
                return admin
        return False
    
    def add_customer(self,user):
        if user in self.users:
            return False
        else:
            self.users.append(user)
            return True
        
    def login_user(self,email,passw):
        if not self.users:
            print("There is no user")
            return False
        for user in self.users:
            if user.email==email and user.password==passw:
                return user
            
        return False
        
            

    def find_user(self,account):
        if not self.users:
            print("There is no user")
            return None
        for user in self.users:
            if user.account==account:
                return user
            
        return None
    
    def loan_balance(self):
        if not self.users:
            print("There is no user")
            return
        balance=0
        for user in self.users:
            print(f"{user.account} has taken {user.loan} loan")
            balance+=user.loan
        print(f"\n{self.name} Bank have given total {balance} Tk loan to Customers\n")
        return
    
    def check_balance(self):
        if not self.users:
            print("There is no user")
            return
        balance=0
        for user in self.users:
            balance+=user.balance

        print(f"{self.name} Bank has total {balance} available balance")

    def users_list(self):
        if not self.users:
            print("There is no user")
            return
        print(f"---------------{self.name} Bank Users List------------\n")
        print("Name\tAccount\t\tBalance \t\tType")
        for user in self.users:
            print(f"{user.name}\t{user.account}\t\t{user.balance} TK\t\t{user.account_type}")
            
        print(f"\n\n{datetime.now()}\n{self.name} Bank\n\n")






class user(ABC):
    def __init__(self,name,email,phone,password,address) -> None:
        self.name=name
        self.email=email
        self.phone=phone
        self.password=password
        self.address=address


def generate_account_number():
    char = string.digits
    account_number = ''.join(random.choice(char) for _ in range(10))
    return int(account_number)


class Customer(user):
    def __init__(self, name, email, phone, password,account_type,address) -> None:
        super().__init__(name, email, phone, password,address)
        self.balance=0
        self.account=generate_account_number()
        self.withdraw_transaction=[]
        self.transfer_transaction=[]
        self.loan_transaction=[]
        self.loan_pay_transaction=[]
        self.deposit_transaction=[]
        self.recevied_transaction=[]
        self.loan=0
        self.loan_count=2
        self.account_type=account_type
        self.loan_permission=True

    def deposit(self,amount):
        self.balance+=amount
        print(f"{amount} have been deposit successfully.\nTotal Balance : {self.balance}")
        tran=Transaction(self.account,amount,datetime.now(),0)
        self.deposit_transaction.append(tran)


    def check_balance(self):
        print(f"{self.name} with account number {self.account} has {self.balance} in this account")


    def withdraw(self,amount):
        if self.balance==0:
            print(f"{self.name} has 0 balance")
        if amount>self.balance:
            print("Withdrawal amount exceeded") 
            return
        self.balance-=amount
        print(f"{amount} withdraw successfull.\nCurrent Balance = {self.balance}")
        tran=Transaction(self.account,amount,datetime.now(),0)
        self.withdraw_transaction.append(tran)

    def check_transaction(self,bank):
        if not self.withdraw_transaction and not self.transfer_transaction and not self.deposit_transaction and not self.loan_transaction and not self.recevied_transaction:
            print("There is No Transaction History\n")
            return
        
        print("\n")
        print("\n---------------Deposit Transaction History-----------------")
        print("Account No\tDeposit_Amount\t\tDate")
        for tran in self.deposit_transaction:
            print(f"{tran.account}\t{tran.amount}\t\t{tran.date}")

        print("\n")
        print("\n---------------Withdraw Transaction History-----------------")
        print("Account No\tAmount\t\tDate")
        for tran in self.withdraw_transaction:
            print(f"{tran.account}\t{tran.amount}\t\t{tran.date}")

        print("\n")
        print("\n---------------Transfer Transaction History-----------------")
        print("Account No\tAmount\tTransfered_Account\t\tDate")
        for tran in self.transfer_transaction:
            print(f"{tran.account}\t{tran.amount}\t{tran.transfer}\t\t{tran.date}")

        print("\n")
        print("\n---------------Recevied Transaction History-----------------")
        print("Account No\tAmount\tSender_Account\t\tDate")
        for tran in self.recevied_transaction:
            print(f"{tran.account}\t{tran.amount}\t{tran.transfer}\t\t{tran.date}")
        

        print("\n")
        print("\n---------------Loan Transaction History-----------------")
        print("Account No\tLoan_Amount\t\tDate")
        for tran in self.loan_transaction:
            print(f"{tran.account}\t{tran.amount}\t\t{tran.date}")

        print("\n")
        print("\n---------------Loan Payment Transaction History-----------------")
        print("Account No\tLoan_Paid\t\tDate")
        for tran in self.loan_pay_transaction:
            print(f"{tran.account}\t{tran.amount}\t\t{tran.date}")

        
        print(f"\n\nCurrent Loan : {self.loan}")
        print(f"\nCurrent Balance = {self.balance}")

        

        print(f"\n\n{datetime.now()}\n{bank.name} Bank\n\n")
        
    def take_loan(self,amount):
        if self.loan_permission == False:
            print("Loan application Rejected!!!\nFor Further inquery contact Bank\n")
        if self.loan_count==0:
            print(f"{self.name} have to pay the previous loan amount to get new loan")
            return
        if amount > self.balance*2:
            print("You have apply for huge amount of loan which is greater than your maximum allowed loan amount for this account\n")
            return
        else:
            self.loan+=amount
            self.balance+=amount
            self.loan_count-=1
            tran=Transaction(self.account,amount,datetime.now(),0)
            self.loan_transaction.append(tran)
            print(f"Loan application Accecpted\nLoan Limit : {self.loan_count}")
        
        print(f"\nCurrent Balance = {self.balance}")    

    def transfer_balance(self,amount,account,bank):
        if self.balance==0:
            print(f"{self.name} has 0 balance")
            return
        if amount>self.balance:
            print("Transfer amount exceeded the balance")
            print(f"\nCurrent Balance = {self.balance}") 
            return
        if not bank.users:
            "There are No users"
            return
        user=bank.find_user(account)
        if user:
            if user.account==account:
                self.balance-=amount
                user.balance+=amount
                print(f"{amount} has been transfered to this account {account}")
                tran=Transaction(self.account,amount,datetime.now(),account)
                self.transfer_transaction.append(tran)
                tran2=Transaction(account,amount,datetime.now(),self.account)
                user.recevied_transaction.append(tran2)
                print(f"\nCurrent Balance = {self.balance}")
                
        else:
            print("Account does not exist")


    def pay_loan(self,amount):
        x=self.loan
        self.loan-=amount
        if self.loan==0:
            print("Congratulation for paying all of your loan\n")
            self.loan_count=2
        elif self.loan>0:
            print(f"Congratulation for paying {amount} for your loan\nRemaining Loan balance : {self.loan}")
        elif self.loan<0:
            print("Congratulation for paying all of your loan and you have paid extra amount which has been deposit in your account\n")
            self.loan_count=2
            self.balance+=(-1*self.loan)
            print(f"{-1*self.loan} has been deposied in your account")
            loan=Transaction(self.account,x,datetime.now(),0)
            self.loan_pay_transaction.append(loan)
            tran=Transaction(self.account,amount-x,datetime.now(),0)
            self.deposit_transaction.append(tran)
            self.loan=0
            return
        tran=Transaction(self.account,amount,datetime.now(),0)
        self.loan_pay_transaction.append(tran)
        print(f"\nCurrent Balance = {self.balance}")





    

class Admin(user):
    def __init__(self, name, email, phone, password,address) -> None:
        super().__init__(name, email, phone, password,address)
        self.permission=True

    def create_user_account(self,bank,user):
        bank.add_customer(user)



    def delete_user_account(self,bank,account):
        user=bank.find_user(account)
        if user:
            bank.users.remove(user)
            print("Account Delete Successfull")
            return
        else:
            print(f"There is no user with this {account}!!!\n")
    
    def bank_loan_feature(self,bank):
        print(f"Bank Loan Feature is",end=" ")
        if bank.loan_permision==True:
            print("ON")
            print("\nTurn OFF Bank Loan Feature : ")
            print("1)Yes\n2)No")
            feat=int(input("Enter Your Choice : "))
            if feat==1:
                bank.loan_permision=False
                print("Bank Loan Permisiion have Updated!!!\n")
            else:
                return

        else:
            print("OFF")
            print("\nTurn ON Bank Loan Feature : ")
            print("1)Yes\n2)No")
            feat=int(input("Enter Your Choice : "))
            if feat==1:
                bank.loan_permision=True
                print("Bank Loan Permisiion have Updated!!!\n")
            else:
                return

    def loan_feature(self,bank,account):
        user=bank.find_user(account)
        if user:
            print(f"{user.name} with account {user.account} loan feature is",end= " ")
            if user.loan_permission==True:
                print("ON")
                print("\nTurn OFF User Loan Feature : ")
                print("1)Yes\n2)No")
                feat=int(input("Enter Your Choice : "))
                if feat==1:
                    user.loan_permission=False
                else:
                    return
            else:
                print("OFF")
                print("\nTurn ON User Loan Feature : ")
                print("1)Yes\n2)No")
                feat=int(input("Enter Your Choice : "))
                if feat==1:
                    user.loan_permission=True
                else:
                    return
            
            print(f"{account} Loan Feature has been updated\n")
            return
        else:
            print(f"There is no user with this {account}!!!\n")

    def check_loan(self,bank):
        bank.loan_balance()

    def check_balance(self,bank):
        bank.check_balance()

    def list_users(self,bank):
        bank.users_list()

    def withdraw_permission(self,bank):
        print(f"Bank WithDraw Feature is",end=" ")
        if bank.withdraw_permision==True:
            print("ON")
            print("\nTurn OFF Bank WithDraw Feature : ")
            print("1)Yes\n2)No")
            feat=int(input("Enter Your Choice : "))
            if feat==1:
                bank.withdraw_permision=False
                print("Bank WithDraw Permisiion have Updated!!!\n")
            else:
                return

        else:
            print("OFF")
            print("\nTurn ON Bank WithDraw Feature : ")
            print("1)Yes\n2)No")
            feat=int(input("Enter Your Choice : "))
            if feat==1:
                bank.withdraw_permision=True
                print("Bank WithDraw Permisiion have Updated!!!\n")
            else:
                return
            



class Transaction:
    def __init__(self,account,amount,date,transfer) -> None:
        self.account=account
        self.amount=amount
        self.date=date
        self.transfer=transfer
    





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

        
            
                

        
