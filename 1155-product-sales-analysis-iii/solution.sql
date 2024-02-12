select p.product_id, first_year, quantity, price
from Sales p
inner join (
    select product_id, min(year) as first_year from Sales group by product_id
) x
on p.product_id = x.product_id
and p.year = first_year


