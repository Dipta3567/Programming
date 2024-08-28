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

            INSERT INTO Student(Roll, Name)
            VALUES('101',"Dipta Dhor")

            """

mycusror.execute(sqlquery)
mydb.commit()
print("Insert in Table successfully")