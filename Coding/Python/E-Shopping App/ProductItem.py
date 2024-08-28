class Product_Item:
    def __init__(self,name,price,quan) -> None:
        self.name=name
        self.price=int(price)
        self.quantity=int(quan)

    #def __repr__(self) -> str:
    #    return self.name