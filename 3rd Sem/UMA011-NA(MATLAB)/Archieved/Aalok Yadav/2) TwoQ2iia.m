clc;
clear all;
f=@ (x) cos(x)-x*exp(x);
tol=0.00001;
x0=1;
n=5;
syms x;
g=diff(f,x);
for i=1:n
    x1=x0-(f(x0)/vpa(subs(g,x0)));
    if abs(x1-x0)<tol
        break
    else
        x0=x1;
    end
end

disp (x1)