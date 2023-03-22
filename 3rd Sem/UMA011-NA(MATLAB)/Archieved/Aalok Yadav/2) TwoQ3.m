clc;
clear all;
f=@ (x) (((1500/x)*((1+x)^240)-1))-750000;
tol=10^-3;
x0=1;
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