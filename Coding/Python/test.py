class Student:
    def __init__(self,name,current_class,id):
        self.name=name
        self.id=id
        self.current_class=current_class

    def __repr__(self) -> str:
        return f'Student with name: {self.name}, Class: {self.current_class}, id: {self.id}'


class Teacher:
    def __init__(self,name,subject,id):
        self.name=name
        self.subject=subject
        self.id=id
    def __repr__(self) -> str:
        return f'Teacher : {self.name}, Subject: {self.subject}, Id: {self.id}'
    

alia=Student('Alia Torkari',9,1)
ranbeer=Teacher('Ranbeer Kapoor', 'Biology',234)
print(alia)
print(ranbeer)











class A:
    def __init__(self, value):
        value = 3
        self.value = value

    def change(self):
        self.value = 12


ans = []
a = A(13)
ans.append(a.value)
a.change()
ans.append(a.value)
print(ans)