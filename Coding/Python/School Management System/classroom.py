class Classroom:
    def __init__(self,name) -> None:
        self.name=name
        self.students=[] #list of student onject
        self.subjects=[] # list of subject object
        self.teachers=[]

    def add_Student(self,student):
        roll_no=f"{self.name}--{len(self.students)+1}"
        student.id=roll_no
        self.students.append(student)

    def add_subjects(self,subject):
        self.subjects.append(subject)
        self.teachers.append(subject.teacher)

    def take_semester_final_exam(self):
        for subject in self.subjects:
            subject.exam(self.students)

        for student in self.students:
            student.calculate_final_grade()
