select round(count(event_date) / (select count(distinct player_id) from Activity),2) as fraction
from Activity as A
left join (
    select player_id, min(event_date) as min_event_date
    from Activity
    group by player_id
) X
on A.player_id = X.player_id
where datediff(A.event_date,min_event_date) = 1
