DECLARE
  n1 NUMBER:=5;
  BEGIN
  IF MOD(N1,2)=0 THEN
  DBMS_OUTPUT.PUT_LINE('Tne Number'||n1||'is even number');
  ELSE
  DBMS_OUTPUT.PUT_LINE('The Number'||n1||'is odd number');
  END IF;
  DBMS_OUTPUT.PUT_LINE('Done Successfully');
 END;
/
