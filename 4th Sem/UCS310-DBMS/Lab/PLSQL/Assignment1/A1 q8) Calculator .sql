declare
a number:=16;
b number:=10;
c number;
d number;
e float;
f number;
begin
c:=a+b;
d:=a-b;
e:=a/b;
f:=a*b;
dbms_output.put_line('the value of Addition is:'||c);
dbms_output.put_line('the value of Subtractrion is:'||d);
dbms_output.put_line('the value of Division is:'||e);
dbms_output.put_line('the value of Multiplication is:'||f);
end;
/
