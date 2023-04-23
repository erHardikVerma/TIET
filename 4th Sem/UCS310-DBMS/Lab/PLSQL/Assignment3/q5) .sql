CREATE OR REPLACE FUNCTION add_numbers (
    a IN NUMBER,
    b IN NUMBER
)
RETURN NUMBER
IS
    c NUMBER;
BEGIN
    c := a + b;
    RETURN c;
END;
/

DECLARE
    c NUMBER;
BEGIN
    c := add_numbers(10, 20);
    DBMS_OUTPUT.PUT_LINE('Sum: ' || c);
END;
/
