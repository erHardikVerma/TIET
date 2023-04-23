declare
x number;
n number;
begin
for x in 1..4 loop
n:=x*5;
dbms_output.put_line(n);
end loop;
end;
/
