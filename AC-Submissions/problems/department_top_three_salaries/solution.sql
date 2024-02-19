select Department, Employee, Salary
from (
    select
    dept.name as Department,
    emp.name Employee,
    emp.salary Salary,
    dense_rank() over(partition by dept.name order by emp.salary desc) rnk
    from Employee emp join Department dept
    on emp.departmentId = dept.id
) rnk_table
where rnk <= 3