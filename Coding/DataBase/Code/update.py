import mysql.connector

db_name="python_test_db"

mydb=mysql.connector.connect(
    host="localhost",
    user="root",
    passwd="password",
    database=db_name
)




mycusror=mydb.cursor()

sqlquery="""

            Update Student
            set Name="Ananada"
            where Name="Dipta Dhor"

            """

mycusror.execute(sqlquery)
mydb.commit()
print("Update in Table successfully")