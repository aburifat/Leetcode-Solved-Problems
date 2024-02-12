select Prices.product_id, round(ifnull(sum(units*price) / sum(units),0),2) as average_price
from Prices left join UnitsSold
on Prices.product_id = UnitsSold.product_id
and UnitsSold.purchase_date >= Prices.start_date
and UnitsSold.purchase_date <= Prices.end_date
group by Prices.product_id
