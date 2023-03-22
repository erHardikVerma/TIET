clc;
clear all;
f=@ (x) x^2-17;
tol=10^-3;
x0=1;
x1=1.5;
for i=0:100
    x2=x1-(((x1-x0)/(f(x1)-f(x0)))*f(x1));
    if abs(x2-x1)<tol
        break
    else
        x0=x1;
        x1=x2;
    end

end
disp (x2)