declare
begin
If(to_char(sysdate,'hh24')>=0 and to_char(sysdate, 'hh24')<=12)
Then dbms_output.put_line('Good Morning');
End If;
end
