from school import School
from person import Student,Teacher
from subject import Subject
from classroom import Classroom

# Create School
school = School("Abc","Dhaka")

# Create Class
eight=Classroom("Eight")
nine=Classroom("Nine")
ten=Classroom("Ten")

# Adding Classrooms
school.add_classroom(eight)
school.add_classroom(nine)
school.add_classroom(ten)

# Create Students
rahim=Student("Rahim", eight)
karim=Student("Karim",nine)
fahim=Student("Fahim",ten)
hamim=Student("Hamim",nine)

# Student Admission
school.student_admission(rahim)
school.student_admission(karim)
school.student_admission(fahim)
school.student_admission(hamim)


# Create Teacher
abul=Teacher("Abul Khan")
babul=Teacher("Babul Khan")
kabul=Teacher("Kabul Khan")

# Adding Subjects
bangla = Subject("Bangla",abul)
physics=Subject("Physics",babul)
chemistry=Subject("Chemistry",kabul)
biology = Subject("Biology",kabul)

# Adding Teacher
school.add_teacher(bangla)
school.add_teacher(physics)
school.add_teacher(chemistry)
school.add_teacher(biology)


# Adding Subjects to Class

eight.add_subjects(bangla)
eight.add_subjects(physics)
eight.add_subjects(chemistry)
nine.add_subjects(biology)
nine.add_subjects(chemistry)
nine.add_subjects(physics)
ten.add_subjects(chemistry)
ten.add_subjects(physics)
ten.add_subjects(bangla)
ten.add_subjects(biology)


eight.take_semester_final_exam()
nine.take_semester_final_exam()
ten.take_semester_final_exam()

print(school)





