clc;
clear all;
x0=1;
f=@ (x) (asin(-(x/2)))/pi;
tol=10^-2;
for i=1:100
    x1=f(x0);
    if abs(x1-x0)<tol
        break
    else
        x0=x1;
    end
    
end
disp(x1)
