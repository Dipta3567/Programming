

class Menu:
    def __init__(self) -> None:
        self.items=[]

    def add_menu_item(self,item):
        self.items.append(item)
        print("Item Added")

    def find_item(self,item_name):
        for item in self.items:
            if item.name.lower()==item_name.lower():
                return item
        
        return None
        
    def remove_item(self,item_name):
        if not self.items:
            print("Menu is empty!!")
            return
        for item in self.items:
            if item_name.lower() ==item.name.lower():
                self.items.remove(item)
                print("Item Deleted")
                return
        else:
            print("Item not found")

    def show_menu(self):
        if not self.items:
            print("Menu is empty!!")
            return
        print("********Menu*********")
        print("Name\tprice\tQuantity")
        for item in self.items:
            print(f"{item.name}\t{item.price}\t{item.quantity}")
