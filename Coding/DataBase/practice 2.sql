
select * from employees;

#Ques 1

select emp.first_name,emp.last_name,jobs.job_title
from employees as emp, jobs
where emp.job_id=jobs.job_id;


#Ques 2

select emp.first_name,emp.last_name,j.job_title
from employees as emp
join jobs as j 
on emp.job_id=j.job_id;


#ques 3

select emp.first_name,emp.last_name,j.job_title
from employees as emp
join jobs as j 
on emp.job_id=j.job_id
where emp.salary=(select max(salary) from employees where job_id=emp.job_id);


#ques 4

select * from employees;

select emp.first_name as Employee, man.first_name as Manager
from employees as emp
left join employees as man
on emp.manager_id=man.employee_id;