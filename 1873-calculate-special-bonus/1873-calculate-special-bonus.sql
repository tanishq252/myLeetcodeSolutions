# Write your MySQL query statement below
# update Employees set salary=0 where mod(employee_id, 2) = 0 or name like "M%";
select employee_id,
case 
    when mod(employee_id, 2) = 0 or name like "M%" then 0
    else salary
end as bonus
from Employees order by employee_id asc;
