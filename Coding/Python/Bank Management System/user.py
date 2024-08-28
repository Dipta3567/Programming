from abc import ABC
import random
import string
from datetime import datetime
from transaction import Transaction
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
