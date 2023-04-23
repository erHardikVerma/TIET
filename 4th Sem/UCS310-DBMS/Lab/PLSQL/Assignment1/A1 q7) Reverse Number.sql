declare 
    num int:=785; 
	rem number;
	rev int:=0;
begin  
	while num>0 loop
    	rem := mod(num,10);
		rev := (rev*10)+rem;
		num := floor(num/10);
	end loop;
dbms_output.put_line(rev);
end;
/
