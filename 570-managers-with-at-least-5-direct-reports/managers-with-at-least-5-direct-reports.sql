
select name from employee where ID in (select managerId from employee group by managerId having count(managerId) > 4);
