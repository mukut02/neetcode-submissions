-- Write your query below
select t1.first_name, t1.last_name, t2.city, t2.state
from person t1
left join address t2
on t1.person_id = t2.person_id;