# Write your MySQL query statement below
select Signups.user_id, round(avg(if(action = 'confirmed',1,0)),2) as confirmation_rate
from Signups left join Confirmations on Signups.user_id = Confirmations.user_id
group by Signups.user_id
