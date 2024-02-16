select
    case
    when
        mod(id, 2) = 1
        then if(id = (select max(id) from Seat), id, id + 1)
    else
        id - 1
    end as id, student
from Seat
order by id;
