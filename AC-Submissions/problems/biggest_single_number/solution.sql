select max(X.num) num
from (
    select num
    from MyNumbers
    group by num
    having count(*) = 1
) X