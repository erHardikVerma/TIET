create or replace function emp_count
	return number is
		cnt number(2) := 0;
	begin
    	select count (*) into cnt
		from emp e;
		return cnt ;
	end;
