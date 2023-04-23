declare
a number;
b number;
c number;
d number;
e number;
f number;
procedure process(a in number,b in number,c out number,d out number,e out number,f out number) is 
begin
c=:a+b;
d:=a-b;
e:=a*b;
f:=a/b;
end process;

begin
a:=6;
b:=3;
process(a,b,c,d,e,f);
dbms_output.put_line('the addition result is'||c);
dbms_output.put_line('the subtraction result is'||d);
dbms_output.put_line('the multiplication result is'||e);
dbms_output.put_line('the division result is'||f);
end;
/
