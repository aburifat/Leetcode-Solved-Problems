select M.employee_id employee_id,
M.name name,
count(E.employee_id) reports_count,
round(avg(E.age),0) average_age
from Employees M join Employees E
on M.employee_id = E.reports_to
group by M.employee_id
having reports_count > 0
order by employee_id