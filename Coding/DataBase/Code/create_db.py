import mysql.connector
mydb=mysql.connector.connect(
    host="localhost",
    user="root",
    passwd="password"
)
print(mydb)

db_name="python_test_db"

mycusror=mydb.cursor()

sqlquery="CREATE DATABASE " + db_name

mycusror.execute(sqlquery)