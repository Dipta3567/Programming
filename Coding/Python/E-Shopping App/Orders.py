class Order:
    def __init__(self) -> None:
        self.items={}

    def add_item(self,item,quantity):
        if item in self.items:
            self.items[item]+=quantity
        else:
            self.items[item]=quantity

    def remove(self,item):
        if item in self.items:
            del self.items[item]
        else:
            print(f"{item} not found\n")

    @property
    def total_price(self):
        return sum(item.price*quantity for item,quantity in self.items.items())

    def clear(self):
        self.items={}
