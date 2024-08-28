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

            CREATE TABLE Student
            (
                Roll varchar(4),
                Name varchar(50)
            )

            """

mycusror.execute(sqlquery)
print("Create Table successfully\n")