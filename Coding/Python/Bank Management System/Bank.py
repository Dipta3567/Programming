from datetime import datetime
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
