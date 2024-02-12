select project_id, round(ifnull(avg(experience_years),0),2) average_years
from Project left join Employee
on Project.employee_id = Employee.employee_id
group by project_id
