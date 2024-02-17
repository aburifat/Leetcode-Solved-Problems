select c1.visited_on as visited_on, sum(c2.amount) as amount, round((sum(c2.amount)/7),2) as average_amount
from (select distinct visited_on from Customer) c1 join Customer c2
on c2.visited_on >= adddate(c1.visited_on, -6)
and c2.visited_on <= c1.visited_on
where c1.visited_on >= (select adddate(min(visited_on),6) from Customer)
group by c1.visited_on
order by c1.visited_on