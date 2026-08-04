-- Write your query below
select employee_id,
case
    when substring(name, 1, 1) != 'M' and employee_id%2=1 then salary
    else 0
end as bonus
from employees
order by employee_id;