clc;
clear all;
x0=1;
f=@ (x) atan(4*x);
tol=0.001;
for i=1:500
    x1=f(x0);
    if abs(x1-x0)<tol
        break
    else
        x0=x1;
    end
    
end
disp(x1)
x2=f(x1);
disp(x2)