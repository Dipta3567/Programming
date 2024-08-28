from Menu import Menu

class Restaurent:
    def __init__(self,name) -> None:
        self.name=name
        self.employees=[] # It will work as data base
        self.menu=Menu()

    def add_employee(self,employee):
        self.employees.append(employee)
        print(f"{employee.name} is added!!")
        
    def view_employee(self):
        if not self.employees:
            print("There is no employee")
            return
        print("************Employee List*************\n")
        print("Name\t\tEmail\t\tPhone\t\tAddress")
        for emp in self.employees:
            print(f"{emp.name}\t\t{emp.email}\t\t{emp.phone}\t\t{emp.address}")
