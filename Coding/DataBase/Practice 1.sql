#Ques1

select * 
From Employees
where salary =(select max(salary) from employees where salary < (select max(salary) from employees where salary< (select max(salary) from employees where salary)));

select distinct salary
from employees order by salary asc;

#ques 2

select * 
From Employees
where salary =(select min(salary) from employees where salary > (select min(salary) from employees where salary> (select min(salary) from employees where salary)));

#ques 3

Select *
From Employees
order by hire_date asc;



Select *
From Employees
where hire_date>(select min(hire_date)
					from employees 
                    where first_name='Steven') 
                    Order By Hire_Date ASC 
                    LIMIT 1;
                    
#Ques 4                    

With ques1 as
(
select max(salary)  as third_highest
from employees 
where salary < (select max(salary) 
				from employees 
                where salary< (select max(salary)
								from employees 
                                where salary))
)
Select * 
From Employees
where salary=(select third_highest from ques1);


with ques2 as
(
select min(salary) as low_salary
from employees 
where salary > (select min(salary)
				from employees 
                where salary> (select min(salary)
								from employees 
                                where salary))
)
 select *
 from employees
 where salary=(select low_salary from ques2);
 

