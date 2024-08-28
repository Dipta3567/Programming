class School:
    def __init__(self,name,address) -> None:
        self.name=name
        self.address=address
        self.teachers={} # {"Bangla" : teacher object}
        self.classrooms={} # {"Eight" : classroom object}

    def add_classroom(self,classroom):
        self.classrooms[classroom.name]=classroom
    
    def add_teacher(self,subject):
        self.teachers[subject.name]=subject.teacher

    def student_admission(self,student):
        classname=student.classroom.name
        self.classrooms[classname].add_Student(student)


    @staticmethod
    def calculate_grade(marks):
        if marks>=80 and marks<=100:
            return 'A+'
        elif marks>=70 and marks<80:
            return 'A'
        elif marks>=60 and marks<70:
            return 'A-'
        elif marks>=50 and marks<60:
            return 'B'
        elif marks>=40 and marks<50:
            return 'C'
        elif marks>=33 and marks<40:
            return 'D'
        else:
            return 'F'
    
    @staticmethod
    def grade_to_value(grade):
        grade_map={
            'A+': 5.00,
            'A': 4.00,
            'A-': 3.50,
            'B': 3.00,
            'C': 2.00,
            'D': 1.00,
            'F': 0.00,
        }
        return grade_map[grade]
    
    @staticmethod
    def value_to_grade(value):
        if value ==5.00:
            return 'A+'
        elif value >=4.00 and value <5.00:
            return 'A'
        elif value >=3.50 and value<4.00:
            return 'A-'
        elif value >=3.00 and value <3.50:
            return 'B'
        elif value >=2.00 and value < 3.00:
            return 'C'
        elif value >=1.00 and value<2.00:
            return 'D'
        elif value>=0.00 and value<1.00:
            return 'F'
        else:
            return 'Invalid Value!!\n'
    
    def __repr__(self) -> str:
        # All Classroom
        print("\nAll Classroom\n")
        for key,value in self.classrooms.items():
            print(key)

        # All Students
        print("\nAll Students\n")
        result=''
        for key,value in self.classrooms.items():
            result+=f"\n\n----{key.upper()} ClassRoom Students\n\n"
            for student in value.students:# akane value modhe students er list
                result+=f"{student.name}\n"

        print(result)
        # All Subjects and teachers

        subject=''
        for key,value in self.classrooms.items():
            subject+=f"\n\n----{key.upper()} ClassRoom Subjects and Teachers\n\n"
            for sub in value.subjects:# akane value modhe students er list
                subject+=f"{sub.name} - {sub.teacher.name}\n"
        print(subject)

        # All Teachers
        teacher=''
        print("\n\n-------All Teachers\n\n")
        for key,value in self.teachers.items():
            teacher+= f"{key} - {value}\n"
        print(teacher)
        # All Student Result
        print("\n\nStudents Result\n\n")
        for key,value in self.classrooms.items():
            print(f"\n\n----{key.upper()} Classroom Student Result\n\n")
            for student in value.students:
                for k,i in student.marks.items():
                    print(student.name, k, i, student.subject_grade[k])
                   
                print(student.calculate_final_grade())
        return ''



