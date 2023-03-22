clc;
clear all;
f=@ (x) (4*(x^2))-(exp(x))-(exp(-x));
tol=10^-5;
x0=10;
n=100;
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