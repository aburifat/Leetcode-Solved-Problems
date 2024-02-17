(
    select name as results from Users
    where user_id in (
        select user_id from (
            select Users.user_id from Users join MovieRating
            on Users.user_id = MovieRating.user_id
            group by Users.user_id
            order by count(rating) desc, Users.name
            limit 1
        ) as MaxUser
    )
)
union all
(
    select title as results from Movies
    where movie_id in (
        select movie_id from (
            select Movies.movie_id from Movies join MovieRating
            on Movies.movie_id = MovieRating.movie_id
            where MovieRating.created_at >= '2020-02-01' and MovieRating.created_at < '2020-03-01'
            group by Movies.movie_id
            order by avg(rating) desc, Movies.title
            limit 1
        ) as avgRatings
    )
)
