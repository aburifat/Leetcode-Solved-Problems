# Write your MySQL query statement below
select r.name
from (
    select m.id, m.name, count(e.id) as ct
    from Employee m left join Employee e
    on m.id = e.managerId
    group by m.id
) r
where ct >= 5
