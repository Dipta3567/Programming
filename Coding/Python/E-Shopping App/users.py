from abc import ABC
from Orders import Order
from shop import Shop        

class user(ABC):
    def __init__(self,name,email,address,phone,password) -> None:
        super().__init__()
        self.name=name
        self.email=email
        self.address=address
        self.phone=phone
        self.password=password

class Seller(user):
    def __init__(self, name, email, address, phone, password) -> None:
        super().__init__(name, email, address, phone, password)
        self.product_list=[]
        self.earn=0


    def add_product(self,shop,item): # here item is object
        shop.shelf.add_product(item)
        self.product_list.append(item)

    def delete_product(self,shop,item):# here item is name
        if not self.product_list:
            print("There are no products\n")
            return
        for pro in self.product_list:
            if pro.name.lower()==item.lower():
                shop.shelf.remove_item(item)
                self.product_list.remove(pro)
                return
        print("Product not found\n")
        return

        

    def view_product(self):
        if not self.product_list:
            print("There are no product\n")
            return
        print("----------------------Product List--------------------")
        print("Product\tprice\tQuantity")
        for pro in self.product_list:
            print(f"{pro.name}\t{pro.price}\t{pro.quantity}")
        print("\n")
        print(f"Total Earned : {self.earn}\n")

class Customer(user):
    def __init__(self, name, email, address, phone, password) -> None:
        super().__init__(name, email, address, phone, password)
        self.cart=Order()

    def view_Products(self,shop):
        shop.shelf.view_products()
        print("\n")
    
    def add_to_cart(self,shop,item_name,quan):
        item=shop.shelf.find_product(item_name)
        if item:
            if int(quan) > int(item.quantity):
                print("Item Quantity exceeded !!!")
            else:
                self.cart.add_item(item,int(quan))
                item.quantity=item.quantity-int(quan)
                product=item
                for seller in shop.seller:
                    for item in seller.product_list:
                        if item_name.lower() == item.name.lower():
                            #item.quantity=item.quantity-int(quan)
                            product=item
                            print("Item Added!!")
                            seller.earn+=int(quan)*int(item.price)
                            return
                product.quantity=product.quantity-int(quan)
                        
        else:
            print("Item Not Found\n")

    def view_cart(self):
        if not self.cart:
            print("Cart is Empty")
        else:
            print("****View Cart****")
            print("Name\tPrice\tQuantity")
            for item,quantity in self.cart.items.items():
                print(f"{item.name}\t{item.price}\t{quantity}")
            print(f"Total price : {self.cart.total_price}")
    
    
    def pay_bill(self):
        print(f"Total Bill {self.cart.total_price} paid successfully\n")
        self.cart.clear()


    

