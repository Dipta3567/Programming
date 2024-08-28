class Products:
    def __init__(self) -> None:
        self.items=[]

    def add_product(self,item):
        self.items.append(item)
        print("Item Added\n")
    
    def find_product(self,item_name):
        #print(self.items)
        for item in self.items:
            #print(item.name.lower())
            #print(item_name.lower())
            if item.name.lower()==item_name.lower():
                return item
        
        return None
    def remove_item(self,item_name):
        for item in self.items:
            if item_name.lower()==item.name.lower():
                self.items.remove(item)
                print("Item Deleted\n")
                return
        else:
            print("Item Not Found\n")
    def view_products(self):
        if not self.items:
            print("There are no product\n")
            return
        print("----------------------Product List--------------------")
        print("Product\tprice\tQuantity")
        for pro in self.items:
            if pro.quantity >0:
                print(f"{pro.name}\t{pro.price}\t{pro.quantity}")


    