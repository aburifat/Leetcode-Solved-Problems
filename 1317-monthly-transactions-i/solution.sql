select date_format(trans_date,'%Y-%m') as month,
country,
count(trans_date) as trans_count,
count(if(state = 'approved', state, null)) as approved_count,
sum(amount) as trans_total_amount,
sum(case when state = 'approved' then amount else 0 end) as approved_total_amount
from Transactions
group by month, country
