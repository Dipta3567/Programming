import random
from school import School
class Person:
    def __init__(self,name) -> None:
        self.name=name


class Teacher(Person):
    def __init__(self, name) -> None:
        super().__init__(name)

    def evaluate_exam(self):
        return random.randint(50,100)
    
    def __repr__(self) -> str:
         return self.name
    
class Student(Person):
    def __init__(self, name,classroom) -> None:
        super().__init__(name)
        self.classroom=classroom # object
        self.__id=None
        self.marks={} # {"Eng" : 78, "ICT" : 90}
        self.subject_grade={} # {"Eng" : 'A', "ICT" : 'A+'}
        self.grade=None

    def calculate_final_grade(self):
        sum=0
        for grade in self.subject_grade.values():
            point=School.grade_to_value(grade)
            sum+=point
        if sum==0:
            gpa=0.00
        else:
            gpa=sum/len(self.subject_grade)
        self.grade=School.value_to_grade(gpa)
        return f"{self.name} Final Grade : {self.grade} with GPA = {gpa}\n"


    @property
    def id(self):
        return self.__id
    @id.setter
    def id(self,value):
        self.__id=value
