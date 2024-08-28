#          Module 2          #
create database programminghero;
use programminghero;

CREATE TABLE Student (
	Roll CHAR(4) PRIMARY KEY,
    Name VARCHAR(50),
    Marks DOUBLE
    );
    
    DROP table student;
    
    
    insert into student (Roll,Name,Marks) VALUES(1,'Dipta',90); 
   insert into student (Roll,Name) VALUES(2,'Akash'); 
   
   SET SQL_SAFE_UPDATES = 0;
   
   UPDATE Student
   SET Name='Dipta Dhor'
   WHERE Roll= 1;
   
   SET SQL_SAFE_UPDATES = 1;
   
   SET SQL_SAFE_UPDATES = 0;
   Delete From Student;
   SET SQL_SAFE_UPDATES = 1;
   
   
   SET SQL_SAFE_UPDATES = 0;
   Delete From Student
   where roll = 2;
   SET SQL_SAFE_UPDATES = 1;
   
   
   
   
   #          Module 3          #
   
   create database module3;
   use module3;
   
   create table student
   (
		Roll char(4) primary key,
		Name varchar(50) NOT NULL,
		Email varchar(60) UNIQUE,
		Adress varchar(255),
		Age INT check(Age>10)
   );
   
   
   
   create table student
   (
		Roll char(4),
		Name varchar(50) NOT NULL, -- Ata ke pashe lekte hobe niche leka jabe na--
		Email varchar(60),
		Adress varchar(255),
		Age INT,
        PRIMARY KEY(Roll),
        UNIQUE(Email),
        CHECK (Age>10)
   );
   

   
   