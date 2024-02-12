select contest_id, round(ifnull(count(distinct user_id) / (select count(user_id) from Users), 0) * 100, 2) as percentage
from Register
group by contest_id
order by percentage desc, contest_id;
