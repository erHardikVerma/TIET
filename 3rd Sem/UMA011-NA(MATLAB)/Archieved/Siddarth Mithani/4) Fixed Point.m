%Fixed Point Method
clc
clear all
g=@(x) (atan(4*x));
x0=0.5;
tol=0.001;
error=inf;
while(error>tol)
    x=g(x0);
    error=abs(x-x0);
    x0=x;
end
x0
