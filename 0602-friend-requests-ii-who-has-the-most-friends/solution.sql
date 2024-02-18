select user_id id, count(friend_id) num from
((select requester_id user_id, accepter_id friend_id from RequestAccepted)
union all
(select accepter_id user_id, requester_id friend_id from RequestAccepted)) as friends
group by id
order by num desc
limit 1

