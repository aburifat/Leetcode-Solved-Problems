select round(sum(tiv_2016),2) as tiv_2016 from Insurance
where pid in (
    select i1.pid
    from Insurance i1 join Insurance i2
    group by i1.pid
    having sum(if((i1.tiv_2015 = i2.tiv_2015), 1, 0)) > 1
    and sum(if(((i1.lat = i2.lat) and (i1.lon = i2.lon)), 1, 0)) = 1
)
