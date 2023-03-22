clc;
clear all;
f=@ (x) exp(-x)*((x^2)+(5*x)+2)+1;
tol=0.00001;
x0=-2;
syms x;
g=diff(f,x);
for i=1:100
    x1=x0-(f(x0)/vpa(subs(g,x0)));
    if abs(x1-x0)<tol
        break
    else
        x0=x1;
    end
end

disp (x1)