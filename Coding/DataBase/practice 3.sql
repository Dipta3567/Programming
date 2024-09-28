create database final;
use final;
CREATE TABLE Student (
    StudentID INT AUTO_INCREMENT PRIMARY KEY,
    Name VARCHAR(255) NOT NULL,
    Email VARCHAR(255) NOT NULL,
    Phone VARCHAR(15),
    Address TEXT
);

CREATE TABLE Book (
    ISBN VARCHAR(13) PRIMARY KEY,
    Title VARCHAR(255) NOT NULL,
    Author VARCHAR(255) NOT NULL,
    Genre VARCHAR(50),
    TotalCopies INT NOT NULL,
    AvailableCopies INT NOT NULL
);

CREATE TABLE Borrowing (
    BorrowID INT AUTO_INCREMENT PRIMARY KEY,
    StudentID INT,
    ISBN VARCHAR(13),
    BorrowDate DATE NOT NULL,
    DueDate DATE NOT NULL,
    ReturnDate DATE,
    FOREIGN KEY (StudentID) REFERENCES Student(StudentID),
    FOREIGN KEY (ISBN) REFERENCES Book(ISBN)
);


Insert INTO Borrowing (StudentID,ISBN,BorrowDate,DueDate)
values(3,
	   (select ISBN from book where AvailableCopies=(select max(AvailableCopies) from book)),
	    current_date(),
        date_add(current_date(),interval 14 DAY)
	  );
      
      
SET SQL_SAFE_UPDATES = 0;
Update Book
Set AvailableCopies= AvailableCopies-1
where ISBN='9781234567890';
SET SQL_SAFE_UPDATES = 1;



Select st.Name
from student as st
join borrowing as br
on st.StudentID=br.StudentID
group by st.StudentID
order by count(br.ISBN) desc
Limit 1;



select *
From Book as ab
join borrowing as cd
on ab.ISBN=cd.ISBN
where (cd.DueDate < current_date() AND cd.ReturnDate IS NULL) OR (cd.ReturnDate > cd.DueDate);







Select column_Name from table1
Union All Select column_name from table2;






select * from student;


SELECT s.Name, COUNT(b.BorrowID) AS NumberOfBooksBorrowed
FROM Student s
JOIN Borrowing b 
ON s.StudentID = b.StudentID
GROUP BY s.StudentID
HAVING COUNT(b.BorrowID) = (
    SELECT max(MaxBooksBorrowed) 
    FROM (
        SELECT COUNT(BorrowID) AS MaxBooksBorrowed
        FROM Borrowing
        GROUP BY StudentID
    ) AS t
);



Select st.Name as Name, count(b.BorrowId) as Number_of_Books
from student as st
join borrowing as b
on st.StudentID=b.StudentID
group by st.StudentID
having count(b.BorrowID)=(Select max(Numbers)
						  from ( select count(BorrowID) as Numbers
								 from borrowing
                                 group by StudentID) as t
						  );


create table Department
(
 Department_ID INT primary key,
 Department_Name varchar(20) Not NULL
);
create table Employee
(
 Employee_ID int primary key,
 Name varchar(50) NOT NULL,
 phone varchar(15) NOT null unique,
 Email varchar(50) unique,
 Department_ID INT,
 foreign key (Department_ID) references Department(Department_ID) on DELETE set NULL
);
create Table JobHistory
(
History_ID int primary key,
Employee_ID Int NOT NULL,
Position varchar(20) NOT NULL,
Join_Date date Not NULL,
Leave_Date date,
foreign key (Employee_ID) references Employee(Employee_ID) on Delete cascade

);



Insert INTO Borrowing (StudentID,ISBN,BorrowDate,DueDate)
values(3,
	   (select ISBN from book where AvailableCopies=(select max(AvailableCopies) from book) Limit 1),
	    current_date(),
        date_add(current_date(),interval 14 DAY)
	  );borrowing




