# Write your MySQL query statement below
select activity_date as day, count(distinct user_id) as active_users
from Activity
where activity_date >= adddate('2019-07-27',interval -29 day)
and activity_date <= '2019-07-27'
group by day
