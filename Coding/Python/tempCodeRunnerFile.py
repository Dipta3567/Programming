class Person:
    def __init__(self,name=None) -> None:
        self.__name=name

    @property
    def name(self):
        return self.__name
    
    @name.setter
    def name(self,value):
        if not isinstance(value,str):
            raise ValueError("Name must be string")
        self.__name=value

p=Person()
p.name="Alice"
print(p.name)