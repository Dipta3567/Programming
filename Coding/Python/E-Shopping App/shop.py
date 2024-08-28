from product import Products
class Shop:
    def __init__(self,Name) -> None:
        self.name=Name
        self.seller=[]  # here will be seller object
        self.customer=[]
        self.shelf=Products()

    def Create_Seller_Account(self,user):
        if user not in self.seller:
            self.seller.append(user)
            return True
        else:
            return False
    
    def Login_seller_account(self,email,passw):
        for user in self.seller:
            if email==user.email and passw==user.password:
                return user
        else:
             print("User Not Found\n")
             return False
        
    def Create_Customer_Account(self,user):
        if user not in self.customer:
            self.customer.append(user)
            return True
        else:
            return False

    def Customer_Login(self,email,passw):
        for user in self.customer:
            if email==user.email and passw==user.password:
                return user
        else:
             print("User Not Found\n")
             return False
