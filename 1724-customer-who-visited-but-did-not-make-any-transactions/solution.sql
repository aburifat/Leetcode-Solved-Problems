# Write your MySQL query statement below
select customer_id, count(visits.visit_id) count_no_trans
from visits left join transactions on visits.visit_id = transactions.visit_id
where transaction_id is null
group by customer_id
